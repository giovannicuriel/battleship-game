#ifndef __LOGIC_TYPES_HPP__
#define __LOGIC_TYPES_HPP__

#include <unistd.h>
#include <map>
#include <string>
#include <iostream>

typedef int16_t Coordinate;
typedef int16_t BombCount;

struct Dimension {
    size_t x;
    size_t y;

    std::string toString() const;
};


struct Point {
    Coordinate x;
    Coordinate y;
    friend bool operator==(const Point& lhs, const Point& rhs);
    friend auto operator<=>(const Point&, const Point&) = default;
    Point operator+(const Point& other) {
        return Point {
            Coordinate(x + other.x),
            Coordinate(y + other.y)
            };
    }
    std::string toString() const;
};
bool operator<(const ::Point& lhs, const ::Point& rhs);
bool operator==(const Point& lhs, const Point& rhs);
std::ostream& operator<<(std::ostream& out, const std::map<::Point, BombCount>& result);

#endif //__LOGIC_TYPES_HPP__
