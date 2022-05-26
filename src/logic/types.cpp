#include <iostream>
#include "types.hpp"

std::ostream& operator<<(std::ostream& out, const ::Dimension& p) {
    out << "(" << p.x << "-" << p.y << ")";
    return out;
}

bool operator<(const ::Point lhs, const ::Point rhs) {
    return (lhs.x < rhs.x) || ((lhs.x == rhs.x) && (lhs.y < rhs.y));
}

std::ostream& operator<<(std::ostream& out, const ::Point& p) {
    out << "[" << p.x << "," << p.y << "]";
    return out;
}

std::ostream& operator<<(std::ostream& out, const std::map<::Point, BombCount>& result) {
    for(const auto& [point, value]: result) {
        out << point << ": " << value << "\n";
    }
    return out;
}
