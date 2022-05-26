#ifndef __LOGIC_TYPES_HPP__
#define __LOGIC_TYPES_HPP__

#include <unistd.h>
#include <map>

typedef int16_t Coordinate;
typedef int16_t BombCount;

struct Dimension {
    size_t x;
    size_t y;
};
std::ostream& operator<<(std::ostream& out, const ::Dimension& p);

struct Point {
    Coordinate x;
    Coordinate y;
    bool operator==(const Point& other) { return x == other.x && y == other.y; }
    friend auto operator<=>(const Point&, const Point&) = default;
    Point operator+(const Point& other) {
        return Point {
            Coordinate(x + other.x),
            Coordinate(y + other.y)
            };
    }
};

std::ostream& operator<<(std::ostream& out, const ::Point& p);
std::ostream& operator<<(std::ostream& out, const std::map<::Point, BombCount>& result);

#endif //__LOGIC_TYPES_HPP__
