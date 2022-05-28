#ifndef __LOGIC_MINEFIELD_HPP__
#define __LOGIC_MINEFIELD_HPP__

#include <list>
#include <map>
#include <iostream>
#include "logic/types.hpp"

class Field {
protected:
    ::Dimension m_Dimension;
    std::list<::Point> m_Bombs;
    BombCount countBombs(const ::Point p) const;
    bool isBombTouched(const ::Point p) const;
    std::map<::Point, BombCount> sweepSurroundings(const ::Point p) const;

public:
    Field();

    virtual void generate(::Dimension d, size_t nBombs);
    virtual std::map<::Point, BombCount> probe(const ::Point p) const;
    virtual std::map<::Point, BombCount> sweep() const;
    virtual std::string toString() const;

    friend std::ostream& operator<<(std::ostream& out, const Field& obj);
};


#endif //__LOGIC_MINEFIELD_HPP__
