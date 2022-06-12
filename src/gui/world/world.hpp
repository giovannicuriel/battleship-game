#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include <vector>
#include <memory>

#include <gui/world/world-object.hpp>

class World {
protected:
    std::vector<WorldObject *> objects;
public:
    World();
    virtual ~World();
    virtual void addWorldObject(WorldObject * object);
    virtual void draw();
};

#endif //__WORLD_HPP__
