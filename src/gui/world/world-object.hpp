#ifndef __WORLD_OBJECT_HPP__
#define __WORLD_OBJECT_HPP__

#include <adapters/sdl-adapter.hpp>
#include <types.hpp>

class WorldObject {
protected:
    SdlAdapter* m_Sdl;
public:
    WorldObject(SdlAdapter* adapter);
    virtual ~WorldObject();
    virtual void draw() = 0;
    virtual bool contains(Point point) = 0;
};

#endif // __WORLD_OBJECT_HPP__
