#ifndef __MOCK_SDL_ADAPTER_HPP__
#define __MOCK_SDL_ADAPTER_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <adapters/sdl-adapter.hpp>

class MockSdlAdapter: public SdlAdapter {
public:
    MOCK_METHOD(int, init, (), (override));
    MOCK_METHOD(void, start, (), (override));
    MOCK_METHOD(void, createWindow, (const char *title, Area area), (override));
    MOCK_METHOD(void, clearRenderer, (), (override));
    MOCK_METHOD(void, render, (), (override));
    MOCK_METHOD(void, setRenderDrawColor, (Color color), (override));
    MOCK_METHOD(void, renderFillRect, (Area rect), (override));
};
#endif // __MOCK_SDL_ADAPTER_HPP__