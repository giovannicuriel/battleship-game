#ifndef __WINDOW_CONTROLLER_HPP__
#define __WINDOW_CONTROLLER_HPP__

#include <gui/world/world.hpp>
#include <gui/window.hpp>
#include <event-broker/event-broker.hpp>

class WindowController {
protected:
    Window m_Window;
    EventBroker* m_EventBroker;
public:
    WindowController(World* world, EventBroker* broker);
    void start();

    Window& getWindow();
};

#endif // __WINDOW_CONTROLLER_HPP__