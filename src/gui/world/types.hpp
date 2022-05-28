#ifndef __DIMENSION_HPP__
#define __DIMENSION_HPP__

#include <SDL.h>
#include <stdint.h>
#include <vector>
#include <iostream>

namespace gui {
typedef SDL_Point Size;
typedef SDL_Point Point;

struct Dimension
{
    SDL_Point min;
    SDL_Point max;
};

struct Area
{
    SDL_Rect rect;
    bool contains(Point p);
};

struct Color
{
    SDL_Color argb;
    Color &operator+=(std::vector<u_int8_t> v);
    Color &operator-=(std::vector<u_int8_t> v);
    void copyFrom(std::vector<u_int8_t> v);
};
}
std::ostream& operator<<(std::ostream& out, const gui::Point &);
#endif //__DIMENSION_HPP__
