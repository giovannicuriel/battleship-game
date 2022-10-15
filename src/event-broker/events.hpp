#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include <types.hpp>

struct Event {};

enum MouseEventType {
    MOUSE_ENTERED,
    MOUSE_EXITED,
    MOUSE_CLICKED
};

struct MouseEvent: public Event {
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

/**
 * Maybe all these functions might have the same name.
 */
class EventFactory {
public:

    virtual Event* buildEmptyEvent() {
        return new Event();
    };
    virtual Event* buildMouseEvent(MouseEventType type, Point point) {
        return new MouseEvent { type: type, point: point };
    };
    virtual Event* buildGameEvent(GameEventType type) {
        return new GameEvent { type: type };
    };
    virtual Event* buildSimpleEvent(std::string message) {
        return new SimpleEvent { message: message };
    };
    virtual Event* buildRefreshWindowEvent() {
        return new RefreshWindowEvent();
    };
};



#endif // _EVENTS_HPP__
