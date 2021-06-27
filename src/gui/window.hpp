#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>
#include <SDL.h>
#include "commons.hpp"
#include "world/world.hpp"

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400

class Window
{
protected:
    SDL_Window *window;
    SDL_Surface *screenSurface;
    World * world;
public:
    Window(World * world);
    virtual ~Window();
    void init();
    void update();

    SDL_Renderer *renderer;
};

#endif // __WINDOW_HPP__