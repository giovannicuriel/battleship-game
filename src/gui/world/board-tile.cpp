#include <gui/world/board-tile.hpp>

#define COLOR_INCREMENT 25

BoardTile::BoardTile(SDL_Renderer *renderer, BoardTileConfig config) : WorldObject(renderer)
{
    this->m_Area.rect = {
        x : config.origin.x,
        y : config.origin.y,
        w : config.size.x,
        h : config.size.y
    };
    this->m_Color.argb = {
        r : 0,
        g : 0,
        b : 255,
        a : 255
    };
    this->m_State = DESELECTED;
}

BoardTile::~BoardTile() {
}

bool BoardTile::contains(Gui::Point point) {
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
        this->m_Color.copyFrom({0, 0, 255, 255});
        break;
    case BLOWN_UP:
        this->m_Color.copyFrom({255, 0, 0, 255});
        break;
    default:
        break;
    }

    SDL_SetRenderDrawColor(this->m_Renderer,
                           this->m_Color.argb.r,
                           this->m_Color.argb.g,
                           this->m_Color.argb.b,
                           this->m_Color.argb.a);
    SDL_RenderFillRect(this->m_Renderer, &this->m_Area.rect);
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
