#include <string>
#include <sstream>
#include "types.hpp"


std::string Dimension::toString() const {
    std::stringstream ss;
    ss << "<" << x << ", " << y << ">";
    return ss.str();
}

bool operator<(const ::Point& lhs, const ::Point& rhs) {
    return (lhs.x < rhs.x) || ((lhs.x == rhs.x) && (lhs.y < rhs.y));
}

std::string Point::toString() const {
    std::stringstream out;
    out << "[" << x << ", " << y << "]";
    return out.str();
}

bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::ostream& operator<<(std::ostream& out, const std::map<::Point, BombCount>& result) {
    for(const auto& [point, value]: result) {
        out << point.toString() << ": " << value << "\n";
    }
    return out;
}
