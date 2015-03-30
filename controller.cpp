#include "controller.h"
#include <map>

using namespace std;

Controller::Controller() {
    model = new Model();
    view = new View("An Ode to Pole Position", 1280, 720);
}

Controller::~Controller() {
    delete model;
    delete view;
}
/**
References:
https://wiki.libsdl.org/SDL_PollEvent
https://wiki.libsdl.org/SDL_Event
*/
void Controller::loop() {
    SDL_Event e;
    unsigned int lastTime = 0, currentTime;
    std::map<SDL_Keycode, Direction> direction;
    //direction[SDLK_UP] = UP;
    //direction[SDLK_DOWN] = DOWN;
    direction[SDLK_LEFT] = LEFT;
    direction[SDLK_RIGHT] = RIGHT;
	
	/**float frameTime = 0;
    float deltaTime = 0;
    const int fps = 60;*/

	while(!model->gameOver()) {
		/**lastTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = (currentTime - lastTime);*/
		
        // Do stuff here to animate as necessary
		view->show(model);
        if (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                return;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym) {
                //case SDLK_DOWN:
               // case SDLK_UP:
                case SDLK_LEFT:
                case SDLK_RIGHT:
					model->go(direction[e.key.keysym.sym]);
					model->calculate();
                break;
                default:
                break;
                }
            case SDL_MOUSEBUTTONDOWN:
                break;
            }
        }
		else { 
			model->direction = STAGNANT;
			model->calculate();
		}
		/**if(deltaTime < (1000 / fps)) {
            SDL_Delay((1000 / fps) - deltaTime);
        }*/
    }
    // TODO: show something nice?
    view->show(model);
    SDL_Delay(500);
}
