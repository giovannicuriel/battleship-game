#ifndef __MOCK_FIELD_HPP__
#define __MOCK_FIELD_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <logic/minefield/minefield.hpp>

class MockField: public Field {
public:
    MockField(): Field() { m_Area = { 0, 0, 10, 10}; };
    MOCK_METHOD(void, generate, (Area a, size_t nBombs), (override));
    MOCK_METHOD((std::map<Point, BombCount>), probe, (const Point p), (const override));
    MOCK_METHOD((std::map<Point, BombCount>), sweep, (), (const override));
};

#endif // __MOCK_FIELD_HPP__