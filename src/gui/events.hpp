#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include <SDL.h>

enum GUIEventType {
    MOUSE_ENTERED,
    MOUSE_EXITED,
    MOUSE_CLICKED
};

struct GUIEvent {
    GUIEventType type;
    SDL_Point point;
};

#endif // __EVENTS_HPP__
