#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include <types.hpp>

struct Event { };

enum MouseEventType {
    MOUSE_ENTERED,
    MOUSE_EXITED,
    MOUSE_CLICKED
};

struct MouseEvent : public Event {
    MouseEventType type;
    Point point;
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

struct RefreshWindowEvent: public Event { };


#endif // _EVENTS_HPP__
