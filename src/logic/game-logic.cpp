#include <iostream>
#include <logic/game-logic.hpp>

GameLogic::GameLogic(BombCount maxBombs):
    m_Bombs(0),
    m_MaxBombs(maxBombs),
    m_IsGameOver(false) {

}
void GameLogic::increaseBlownUpBombCount() {
    m_Bombs++;
}
bool GameLogic::isGameOver() {
    return m_Bombs == m_MaxBombs;
}
