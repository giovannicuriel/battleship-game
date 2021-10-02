#ifndef __GUI_EVENTS_HPP__
#define __GUI_EVENTS_HPP__

#include <SDL.h>

enum GUIEventType
{
    MOUSE_ENTERED,
    MOUSE_EXITED,
    MOUSE_CLICKED
};

struct GUIEvent
{
    GUIEventType type;
    SDL_Point point;
};

#endif // __GUI_EVENTS_HPP__
