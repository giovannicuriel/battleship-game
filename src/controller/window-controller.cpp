#include <controller/window-controller.hpp>
#include <event-broker/topics.hpp>

WindowController::WindowController(World* world, EventBroker* broker, SdlAdapter* adapter):
    m_Window(world, adapter),
    m_EventBroker(broker),
    m_Sdl(adapter) {
    m_Window.init();
}
Window& WindowController::getWindow() {
    return m_Window;
}

void WindowController::start() {
    m_EventBroker->subscribe(SYSTEM_EVENTS_TOPIC, this);
    m_Sdl->start();
}

void WindowController::processEvent(Event* event) {
    // Should we test for event type?
    m_Window.update();
}
