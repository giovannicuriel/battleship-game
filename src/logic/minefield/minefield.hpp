#ifndef __LOGIC_MINEFIELD_HPP__
#define __LOGIC_MINEFIELD_HPP__

#include <list>
#include <map>
#include <iostream>
#include <types.hpp>

class Field {
protected:
    Area m_Area;
    std::list<Point> m_Bombs;
    BombCount countBombs(const Point p) const;
    bool isBombTouched(const Point p) const;
    std::map<Point, BombCount> sweepSurroundings(const Point p) const;

public:
    Field();

    virtual void generate(Area a, size_t nBombs);
    virtual std::map<Point, BombCount> probe(const Point p) const;
    virtual std::map<Point, BombCount> sweep() const;
    friend std::ostream& operator<<(std::ostream& out, const Field& obj);
};


#endif //__LOGIC_MINEFIELD_HPP__
