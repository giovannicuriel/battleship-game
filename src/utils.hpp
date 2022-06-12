#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <types.hpp>
#include <logic/minefield/minefield.hpp>

std::ostream& operator<<(std::ostream& out, const Point& p);
std::ostream& operator<<(std::ostream& out, const Area& area);
std::ostream& operator<<(std::ostream& out, const std::map<Point, BombCount>& result);
std::ostream& operator<<(std::ostream& out, const Field& obj);

#endif // __UTILS_HPP__