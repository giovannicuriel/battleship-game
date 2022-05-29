#ifndef __BOARD_TILE_HPP__
#define __BOARD_TILE_HPP__

#include "gui/types.hpp"
#include "gui/world/world-object.hpp"
#include <logic/types.hpp>

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
    Gui::Point origin;
    Gui::Size size;
    ::Point coordinate;
};

class BoardTile : public WorldObject
{
protected:
    BoardTileState m_State;
    Gui::Area m_Area;
    Gui::Color m_Color;
    ::Point m_Coordinate;
public:
    BoardTile(SDL_Renderer *renderer, BoardTileConfig config);
    virtual ~BoardTile();

    void draw() override;
    bool contains(Gui::Point point) override;
    void setState(BoardTileState state);
    ::Point getCoordinate() const;
};

#endif // __BOARD_TILE_HPP__
