#include <utils.hpp>

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Area& area) {
    out << "(" << area.x << ", " << area.y << ", w:" << area.w << ", h:" << area.h << ")";
    return out;
}

std::ostream& operator<<(std::ostream& out, const std::map<Point, BombCount>& result) {
    for(const auto& [point, value]: result) {
        out << point << ": " << value << "\n";
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Field& obj) {
    out << "Area: " << obj.m_Area << "\n";
    out << "Bombs are: \n";
    for (auto b: obj.m_Bombs) {
        out << "   " << b << "\n";
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
    out << "(" << (int)c.r << ", " << (int)c.g << ", " << (int)c.b << "|" << (int)c.a << ")";
    return out;
}