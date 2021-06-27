#include <iostream>
using namespace std;
#include "world/board-tile.hpp"

#define COLOR_INCREMENT 25

BoardTile::BoardTile(SDL_Renderer *renderer, Point origin, Size size) : WorldObject(renderer)
{
    this->area.rect = {
        x : origin.x,
        y : origin.y,
        w : size.x,
        h : size.y
    };
    this->color.argb = {
        r : 0,
        g : 0,
        b : 130,
        a : 255
    };
    this->state = IDLE;
}

BoardTile::~BoardTile()
{
}

void BoardTile::processEvent(GUIEvent event)
{
    if (this->area.contains(event.point))
    {
        switch (event.type)
        {
        case MOUSE_ENTERED:
            if (this->state != SELECTED)
            {
                this->state = FADING_IN;
            }

            break;
        case MOUSE_EXITED:
            if (this->state != SELECTED)
            {
                this->state = FADING_OUT;
            }
            break;
        case MOUSE_CLICKED:
            if (this->state == SELECTED)
            {
                this->state = FADING_IN;
            }
            else
            {
                this->state = SELECTED;
            }
            break;
        default:
            break;
        };
    }
    else
    {
        if (this->state == FADING_IN || this->state == IDLE)
        {
            this->state = FADING_OUT;
        }
    }
}
void BoardTile::draw()
{
    switch (this->state)
    {
    case FADING_IN:
        // Going to blue
        this->color += {0, 0, COLOR_INCREMENT, 0};
        this->color -= {COLOR_INCREMENT, 0, 0, 0};
        if (this->color.argb.b == 255)
        {
            this->state = IDLE;
        }
        break;
    case FADING_OUT:
        // Going to red
        this->color += {COLOR_INCREMENT, 0, 0, 0};
        this->color -= {0, 0, COLOR_INCREMENT, 0};
        if (this->color.argb.r == 255)
        {
            this->state = IDLE;
        }
        break;
    case SELECTED:
        this->color.copyFrom({0, 255, 0, 255});
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
