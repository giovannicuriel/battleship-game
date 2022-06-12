#ifndef __MOCK_GUI_WORLD_HPP__
#define __MOCK_GUI_WORLD_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <gui/world/world.hpp>

class MockWorld: public World {
public:
    MOCK_METHOD(void, addWorldObject, (WorldObject * object), (override));
    MOCK_METHOD(void, draw, (), (override));
};

#endif // __MOCK_GUI_WORLD_HPP__