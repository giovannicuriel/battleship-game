#ifndef __ADAPTERS_SDL_ADAPTER_HPP__
#define __ADAPTERS_SDL_ADAPTER_HPP__

#include <types.hpp>

class SdlAdapter {
public:
    virtual int init() = 0;
    virtual void start() = 0;
    virtual void createWindow(const char *title, Area area) = 0;
    virtual void clearRenderer() = 0;
    virtual void render() = 0;
    virtual void setRenderDrawColor(Color color) = 0;
    virtual void renderFillRect(Area rect) = 0;
};

#endif // __ADAPTERS_SDL_ADAPTER_HPP__
