#ifndef __WINDOW_CONTROLLER_HPP__
#define __WINDOW_CONTROLLER_HPP__

#include <gui/window.hpp>
#include <event-broker/event-broker.hpp>
#include <adapters/sdl-adapter.hpp>

class WindowController: public Subscriber  {
protected:
    Window m_Window;
    EventBroker* m_EventBroker;
    SdlAdapter* m_Sdl;
public:
    WindowController(EventBroker* broker, SdlAdapter* sdlAdapter);
    void start();

    Window& getWindow();
    void processEvent(Event* event);
};

#endif // __WINDOW_CONTROLLER_HPP__