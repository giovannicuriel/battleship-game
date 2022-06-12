#include <gui/world/board-tile.hpp>

#define COLOR_INCREMENT 25

BoardTile::BoardTile(SdlAdapter* adapter, BoardTileConfig config) :
    WorldObject(adapter),
    m_Coordinate(config.coordinate),
    m_Count(0) {
    this->m_Area = config.area;
    this->m_Color = {
        r : 0,
        g : 0,
        b : 255,
        a : 255
    };
    this->m_State = DESELECTED;
}

BoardTile::~BoardTile() {
}

bool BoardTile::contains(Point point) {
    return this->m_Area.contains(point);
}

void BoardTile::setState(BoardTileState state) {
    this->m_State = state;
}

void BoardTile::draw()
{
    switch (this->m_State)
    {
    case SELECTED:
        this->m_Color.copyFrom({0, 255, 0, 255});
        break;
    case DESELECTED:
        this->m_Color.copyFrom({m_Count * 60, 0, 255, 255});
        break;
    case BLOWN_UP:
        this->m_Color.copyFrom({255, 0, 0, 255});
        break;
    default:
        break;
    }

    m_Sdl->setRenderDrawColor(this->m_Color);
    m_Sdl->renderFillRect(this->m_Area);
}

BoardTileState operator!(BoardTileState state)
{
    switch (state)
    {
    case BoardTileState::FADING_OUT:
        return BoardTileState::FADING_IN;
    case BoardTileState::FADING_IN:
        return BoardTileState::FADING_OUT;
    case BoardTileState::SELECTED:
        return BoardTileState::DESELECTED;
    case BoardTileState::DESELECTED:
        return BoardTileState::SELECTED;
    default:
        return BoardTileState::IDLE;
    }
}

Point BoardTile::getCoordinate() const {
    return m_Coordinate;
}

void BoardTile::setSurroundingBombCount(BombCount count) {
    m_Count = count;
}