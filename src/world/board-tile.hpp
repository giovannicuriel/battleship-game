#ifndef __BOARD_TILE_HPP__
#define __BOARD_TILE_HPP__

#include "commons.hpp"
#include "world/world-object.hpp"

enum BoardTileState
{
    IDLE,
    FADING_IN,
    FADING_OUT,
    SELECTED,
    DESELECTED,
    BLOWN_UP
};

BoardTileState operator!(BoardTileState state);

struct BoardTileConfig
{
    Point origin;
    Size size;
    bool hasShip;
};

class BoardTile : public WorldObject
{
protected:
    BoardTileState state;
    Area area;
    Color color;
    bool hasShip;

public:
    BoardTile(SDL_Renderer *renderer, BoardTileConfig config);
    virtual ~BoardTile();

    void processEvent(GUIEvent event) override;
    void draw() override;
};

#endif // __BOARD_TILE_HPP__
