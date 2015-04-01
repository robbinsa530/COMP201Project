#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>

#ifndef _MODEL_H
#define _MODEL_H

enum Direction { LEFT, RIGHT, STAGNANT };

class Debris {
public:
	//constructor initializes coordinates of debris
	Debris();
	//source coordinates (x,y,w,h)
	SDL_Rect source;
	//destination coordinates (x,y)
	SDL_Rect dest;
	//obstacle itself
	SDL_Surface* debris_image;
};

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Is the game over?
    bool gameOver();
	//game over token
	bool game_over;
	//direction of car
	Direction direction;
	//update direction of car
	void go(Direction d);
	//update locations of images
	void calculate();
	//how many pixels will the objects redraw at a time
	int p; ///using a short name because it comes up so much and im lazy
	//obstacles
	std::list<Debris> obstacles;

	//SDL location variables for images
	SDL_Rect source_road_1, source_road_2;
	SDL_Rect destination_road_1, destination_road_2, destination_car;
	
};

#endif