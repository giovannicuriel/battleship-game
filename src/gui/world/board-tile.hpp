#ifndef __BOARD_TILE_HPP__
#define __BOARD_TILE_HPP__

#include <types.hpp>
#include <gui/world/world-object.hpp>
#include <types.hpp>

enum BoardTileState {
    IDLE,
    FADING_IN,
    FADING_OUT,
    SELECTED,
    DESELECTED,
    BLOWN_UP
};

BoardTileState operator!(BoardTileState state);

struct BoardTileConfig {
    Area area;
    Point coordinate;
};

class BoardTile : public WorldObject {
protected:
    BoardTileState m_State;
    Area m_Area;
    Color m_Color;
    Point m_Coordinate;
    BombCount m_Count;
public:
    BoardTile(SdlAdapter* adapter, BoardTileConfig config);
    virtual ~BoardTile();

    void draw() override;
    bool contains(Point point) override;
    void setState(BoardTileState state);
    void setSurroundingBombCount(BombCount count);
    ::Point getCoordinate() const;
};

#endif // __BOARD_TILE_HPP__
