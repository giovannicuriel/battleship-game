#ifndef __BOARD_TILE_HPP__
#define __BOARD_TILE_HPP__

#include "commons.hpp"
#include "world/world-object.hpp"

class GameLogic;

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
    GameLogic * logic;
};

class BoardTile : public WorldObject
{
protected:
    BoardTileState state;
    Area area;
    Color color;
    bool hasShip;
    GameLogic * logic;

public:
    BoardTile(SDL_Renderer *renderer, GameLogic *logic, BoardTileConfig config);
    virtual ~BoardTile();

    void processEvent(GUIEvent event) override;
    void draw() override;
    bool contains(Point point) override;
    bool hidesShip();
};

#endif // __BOARD_TILE_HPP__
