#ifndef __GAME_LOGIC_HPP__
#define __GAME_LOGIC_HPP__

#include <list>
#include "gui/world/board-tile.hpp"

class GameLogic
{
protected:
    bool isGameOver;
public:
    GameLogic();
    virtual ~GameLogic();
};

#endif // __GAME_LOGIC_HPP__
