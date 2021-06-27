#include "world/world.hpp"

World::World()
{
    this->objects.clear();
}

World::~World()
{
    this->objects.clear();
}

void World::addWorldObject(WorldObject * object)
{
    this->objects.push_back(object);
}

void World::processEvent(GUIEvent event)
{
    for (auto obj: this->objects) {
        obj->processEvent(event);
    }
}

void World::draw()
{
    for (auto obj: this->objects) {
        obj->draw();
    }
}
