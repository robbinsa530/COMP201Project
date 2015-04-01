#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model() {
	//initialize location variables for road and car
	source_road_1.x = 0;
	source_road_1.y = 0;
	source_road_1.w = 1280;
	source_road_1.h = 720;
	destination_road_1.y = 0;
	destination_road_1.x = 0;
	
	source_road_2.x = 0;
	source_road_2.y = 720;
	source_road_2.w = 1280;
	source_road_2.h = 0;
	destination_road_2.y = 0;
	destination_road_2.x = 0;
	
	destination_car.y = 530;
	destination_car.x = 490;
	
	p = 2;
	
	//at start of game, game is NOT over
	game_over = false;
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
	
}

bool Model::gameOver() {
	//collision detection  						Doesnt work half the time when hitting obstacle from the right side. FIX***********
	for (std::list<Debris>::iterator it = obstacles.begin(); it != obstacles.end(); it++) {
		game_over = (((it->dest.y + it->source.h) >= 530) && !(destination_car.x + 121 < it->dest.x || destination_car.x > it->dest.x + it->source.w));
	}
	return game_over;
}

void Model::go(Direction d)
{
	direction = d;
	return;
}

void Model::calculate()
{
	//update bottom part of road image
	source_road_1.h = source_road_1.h - p;
    destination_road_1.y = destination_road_1.y + p;
	
	//update top part of road image
    source_road_2.y = source_road_2.y - p;
    source_road_2.h = source_road_2.h + p; 
	
	//reset road image after every loop through
	if (source_road_2.y == 0 || source_road_2.h == 720) {
		source_road_1.h = 720;
		destination_road_1.y = 0;
		source_road_2.y = 720;
		source_road_2.h = 0;
	}
	
	//updates car position
	switch(direction)
	{
		case LEFT: destination_car.x = destination_car.x - 4;
		break;
		case RIGHT: destination_car.x = destination_car.x + 4;
		break;
		case STAGNANT:
		break;
	}
	
	//update obstacle positions
	for (std::list<Debris>::iterator it = obstacles.begin(); it != obstacles.end(); it++) {
		it->dest.y = it->dest.y + p;	
			if (it->source.y > 0) {
				it->source.y = it->source.y - p;
				it->source.h = it->source.h + p;
				it->dest.y = it->dest.y - p;
		}
		//check if image is off screen. if so, pop that ish outa hurr
		if (it->dest.y > 720) {
			//just do pop_front instead of getting rid of the specific debris because the only obstacle which will be this far down at any 
			//given time is the first element (oldest one)
			obstacles.pop_front();
		}
	}
	return;
}

Debris::Debris() {
	source.x = 0;
	source.y = 120;
	source.w = 100;
	source.h = 1;
	dest.y = 0;
	//dest.x is set randomly in controller
}

