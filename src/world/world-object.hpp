#ifndef __WORLD_OBJECT_HPP__
#define __WORLD_OBJECT_HPP__

#include <SDL.h>
#include "gui/events.hpp"

class WorldObject {
protected:
    SDL_Renderer* renderer;
public:
    WorldObject(SDL_Renderer* renderer);
    virtual ~WorldObject();
    virtual void processEvent(GUIEvent event) = 0;
    virtual void draw() = 0;
};

#endif // __WORLD_OBJECT_HPP__
