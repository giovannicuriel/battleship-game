#ifndef __GUI_EVENTS_HPP__
#define __GUI_EVENTS_HPP__

#include <SDL.h>
#include <event-broker/events.hpp>
#include <gui/types.hpp>

enum MouseEventType
{
    MOUSE_ENTERED,
    MOUSE_EXITED,
    MOUSE_CLICKED
};

struct MouseEvent : public Event
{
    MouseEventType type;
    Gui::Point point;
};

enum GameEventType {
    BOMB_BLOWN_UP,
    AREA_CLEARED,
    GAME_OVER
};

struct GameEvent: public Event {
    GameEventType type;
};

struct SimpleEvent: public Event {
    std::string message;
};

#endif // __GUI_EVENTS_HPP__
