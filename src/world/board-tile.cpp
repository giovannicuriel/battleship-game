#include <iostream>
#include "logic/game-logic.hpp"
#include "world/board-tile.hpp"

#define COLOR_INCREMENT 25

BoardTile::BoardTile(SDL_Renderer *renderer, GameLogic * logic, BoardTileConfig config) : WorldObject(renderer)
{
    this->area.rect = {
        x : config.origin.x,
        y : config.origin.y,
        w : config.size.x,
        h : config.size.y
    };
    this->color.argb = {
        r : 0,
        g : 0,
        b : 255,
        a : 255
    };
    this->state = DESELECTED;
    this->hasShip = config.hasShip;
    this->logic = logic;
}

BoardTile::~BoardTile()
{
}

bool BoardTile::contains(Point point) {
    return this->area.contains(point);
}

void BoardTile::processEvent(GUIEvent event)
{
    if ((event.type == MOUSE_CLICKED) && (this->area.contains(event.point)))
    {
        if (this->hasShip)
        {
            this->state = BLOWN_UP;
            logic->blowUpTile(this);
        }
        else
        {
            this->state = !this->state;
        }
    }
}

void BoardTile::draw()
{
    switch (this->state)
    {
    case SELECTED:
        this->color.copyFrom({0, 255, 0, 255});
        break;
    case DESELECTED:
        this->color.copyFrom({0, 0, 255, 255});
        break;
    case BLOWN_UP:
        this->color.copyFrom({255, 0, 0, 255});
        break;
    default:
        break;
    }

    SDL_SetRenderDrawColor(this->renderer,
                           this->color.argb.r,
                           this->color.argb.g,
                           this->color.argb.b,
                           this->color.argb.a);
    SDL_RenderFillRect(this->renderer, &this->area.rect);
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


bool BoardTile::hidesShip() { return this->hasShip; };
