#ifndef __GUI_EVENTS_HPP__
#define __GUI_EVENTS_HPP__

#include <SDL.h>
#include <event-broker/events.hpp>
#include <gui/types.hpp>

enum GuiEventType
{
    MOUSE_ENTERED,
    MOUSE_EXITED,
    MOUSE_CLICKED
};

struct GuiEvent : public Event
{
    GuiEventType type;
    Gui::Point point;
};

#endif // __GUI_EVENTS_HPP__
