#include <sstream>
#include "minefield.hpp"

Field::Field() {
}

void Field::generate(Dimension d, size_t nBombs) {
    m_Dimension = d;
    m_Bombs.clear();
    for (size_t i = 0; i < nBombs; i++) {
        m_Bombs.push_back(Point {
            Coordinate(rand() % d.x),
            Coordinate(rand() % d.y)
        });
    }
}

bool Field::isBombTouched(const Point p) const {
    for (auto bomb: m_Bombs) {
        if (p == bomb) {
            return true;
        }
    }
    return false;
}

std::map<Point, BombCount> Field::sweepSurroundings(const Point p) const {
    std::map<Point, BombCount> result;
    Point surroundingPoint;
    size_t counter = 0;
    // Is there a way to build a python-generator like based on Point?
    for (Coordinate x = -1; x <= 1; x++) {
        for (Coordinate y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) { continue; }
            surroundingPoint = Point { x, y } + p;
            result[surroundingPoint] = countBombs(surroundingPoint);
            counter++;
        }
    }
    return result;
}

std::map<Point, BombCount> Field::probe(const Point p) const {
    std::map<Point, BombCount> result;
    if (isBombTouched(p)) {
        result[p] = -1;
        return result;
    }
    return sweepSurroundings(p);
}

BombCount Field::countBombs(const Point p) const {
    BombCount result = 0;
    for (Coordinate x = -1; x <= 1; x++) {
        for (Coordinate y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) { continue; }
            Point probePoint = Point { x, y } + p;
            for (auto b: m_Bombs) {
                if (b == probePoint) {
                    result++;
                }
            }
        }
    }
    return result;
}


std::map<Point, int16_t> Field::sweep() const {
    std::map<Point, int16_t> result;
    for (auto b: m_Bombs) {
        result[b] = -1;
    }

    for (Coordinate x = 0; x < m_Dimension.x; x++) {
        for (Coordinate y = 0; y < m_Dimension.y; y++) {
            Point p = { x, y };
            if (result.contains(p)) { continue; }
            result[p] = countBombs(p);
        }
    }
    return result;
}

std::string Field::toString() const {
    std::stringstream ss;
    ss << "Dimensions: " << m_Dimension.toString() << "\n";
    ss << "Bombs are: \n";
    for (auto b: m_Bombs) {
        ss << "   " << b.toString() << "\n";
    }
    return ss.str();
}

std::ostream& operator<<(std::ostream& out, const Field& obj) {
    out << obj;
    return out;
}
