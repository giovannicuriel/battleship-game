#ifndef __MOCK_GUI_WINDOW_HPP__
#define __MOCK_GUI_WINDOW_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <gui/window.hpp>

class MockWindow: public Window {
public:
    MOCK_METHOD(void, init, (), (override));
    MOCK_METHOD(void, update, (), (override));
    MOCK_METHOD(void, addObject, (WorldObject* worldObj), (override));
    MOCK_METHOD(SdlAdapter*, getSdlAdapter, (), (override));
    MockWindow(): Window(nullptr, nullptr) { };
    ~MockWindow() {}
};

#endif // __MOCK_WINDOW_HPP__