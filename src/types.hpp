#ifndef __DIMENSION_HPP__
#define __DIMENSION_HPP__

#include <stdint.h>
#include <vector>
#include <iostream>
#include <map>

typedef int16_t BombCount;
typedef int16_t Coordinate;

struct Point {
    int32_t x;
    int32_t y;
    Point operator+(const Point& other);
    auto operator<=>(const Point&) const = default;
};

typedef Point Size;

struct Area {
    int32_t x, y;
    int32_t w, h;
    bool contains(Point p);
};
std::ostream& operator<<(std::ostream& out, const Area& c);

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    Color &operator+=(std::vector<u_int8_t> v);
    Color &operator-=(std::vector<u_int8_t> v);
    void copyFrom(std::vector<u_int8_t> v);
};

#endif //__DIMENSION_HPP__
