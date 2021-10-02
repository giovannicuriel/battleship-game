#include <iostream>
#include "game-logic.hpp"

GameLogic::GameLogic() {

}

GameLogic::~GameLogic() {

}

void GameLogic::addBoardTile(BoardTile * tile) {
    if (tile->hidesShip()) {
        this->boardTilesWithShips.push_back(tile);
    }
};
void GameLogic::blowUpTile(BoardTile * tile) {
    this->boardTilesWithShips.remove(tile);
    if (this->boardTilesWithShips.size() == 0) {
        this->isGameOver = true;
        std::cout << "You win!\n";
    }
};