#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>
#include <SDL.h>
#include <gui/types.hpp>
#include <gui/world/world.hpp>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400

class Window
{
protected:
    SDL_Window* m_Window;
    SDL_Surface* m_ScreenSurface;
    World* m_World;
public:
    Window(World * world);
    virtual ~Window();
    void init();
    void update();
    void addObject(WorldObject* worldObj);

    SDL_Renderer *m_Renderer;
};

#endif // __WINDOW_HPP__