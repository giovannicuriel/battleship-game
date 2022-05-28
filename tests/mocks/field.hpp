#ifndef __MOCK_FIELD_HPP__
#define __MOCK_FIELD_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <logic/minefield/minefield.hpp>

class MockField: public Field {
public:
    MockField(): Field() { };
    MOCK_METHOD(void, generate, (::Dimension d, size_t nBombs), (override));
    MOCK_METHOD((std::map<::Point, BombCount>), probe, (const ::Point p), (const override));
    MOCK_METHOD((std::map<::Point, BombCount>), sweep, (), (const override));
    MOCK_METHOD((std::string), toString, (), (const override));
};

#endif // __MOCK_FIELD_HPP__