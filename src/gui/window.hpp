#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>
#include <gui/world/world.hpp>
#include <adapters/sdl-adapter.hpp>

/**
 * These values might come from a config file.
 */
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400

class Window {
protected:
    World* m_World;
    SdlAdapter* m_Sdl;
public:
    Window(World * world, SdlAdapter* adapter);
    virtual void init();
    virtual void update();
    virtual void addObject(WorldObject* worldObj);
    virtual SdlAdapter* getSdlAdapter() { return m_Sdl; }
};

#endif // __WINDOW_HPP__
