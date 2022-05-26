#ifndef __GAME_LOGIC_HPP__
#define __GAME_LOGIC_HPP__

#include <list>
#include "gui/world/board-tile.hpp"

class GameLogic
{
protected:
    std::list<BoardTile*> boardTilesWithShips;
    bool isGameOver;
public:
    GameLogic();
    virtual ~GameLogic();

    void addBoardTile(BoardTile * tile);
    void blowUpTile(BoardTile * tile);
};

#endif // __GAME_LOGIC_HPP__
