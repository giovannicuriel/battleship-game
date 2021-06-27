#ifndef __BOARD_TILE_HPP__
#define __BOARD_TILE_HPP__

#include "commons.hpp"
#include "world/world-object.hpp"

enum BoardTileState {
    IDLE,
    FADING_IN,
    FADING_OUT,
    SELECTED
};

class BoardTile: public WorldObject {
protected:
    BoardTileState state;
    Area area;
    Color color;
public:
    BoardTile(SDL_Renderer* renderer, Point origin, Size size);
    virtual ~BoardTile();

    void processEvent(GUIEvent event) override;
    void draw() override;
};

#endif // __BOARD_TILE_HPP__
