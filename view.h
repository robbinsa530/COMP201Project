#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "model.h"
#include <map>
#include <string>

#ifndef _VIEW_H
#define _VIEW_H

// Show (output) the state of the model
class View {
public:
    View(std::string title, int width, int height);
    ~View();
    // Print out the visible stuff in the grid
    void show(Model * model);
	//obstacles
	SDL_Surface* obst[3];

private:
    SDL_Window* window;
    SDL_Surface* screen;
	//object road and car
	SDL_Surface* road;
	SDL_Surface* car;
    bool fail;
	//load images
	SDL_Surface* load(char * path);
//    SDL_Surface* text;
//    Mix_Music * music;
//    Mix_Chunk * food;
    TTF_Font * font;
};
#endif