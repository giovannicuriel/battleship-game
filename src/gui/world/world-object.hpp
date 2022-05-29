#ifndef __WORLD_OBJECT_HPP__
#define __WORLD_OBJECT_HPP__

#include <SDL.h>
#include "gui/events.hpp"
#include "gui/types.hpp"

class WorldObject {
protected:
    SDL_Renderer* m_Renderer;
public:
    WorldObject(SDL_Renderer* renderer);
    virtual ~WorldObject();
    virtual void draw() = 0;
    virtual bool contains(Gui::Point point) = 0;
};

#endif // __WORLD_OBJECT_HPP__
