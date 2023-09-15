#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>
#include <adapters/sdl-adapter.hpp>

/**
 * These values might come from a config file.
 */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

class Window {
protected:
    SdlAdapter* m_Sdl;
public:
    Window(SdlAdapter* adapter);
    virtual void init();
    virtual void update();
    virtual SdlAdapter* getSdlAdapter() { return m_Sdl; }
};

#endif // __WINDOW_HPP__
