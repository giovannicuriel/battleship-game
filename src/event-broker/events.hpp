#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

typedef u_int16_t Coordinate;

struct Event { };

struct MouseClickedEvent: public Event {
    Coordinate x;
    Coordinate y;
};

#endif // _EVENTS_HPP__
