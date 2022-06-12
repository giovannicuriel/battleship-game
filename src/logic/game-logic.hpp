#ifndef __GAME_LOGIC_HPP__
#define __GAME_LOGIC_HPP__

#include <types.hpp>

class GameLogic
{
protected:
    bool m_IsGameOver;
    BombCount m_Bombs;
    BombCount m_MaxBombs;
public:
    GameLogic(BombCount maxBombs);

    void increaseBlownUpBombCount();
    bool isGameOver();
};

#endif // __GAME_LOGIC_HPP__
