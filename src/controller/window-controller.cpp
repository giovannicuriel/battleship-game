#include <controller/window-controller.hpp>
#include <gui/world/world.hpp>
#include <gui/world/board-tile.hpp>
#include <gui/window.hpp>
#include <gui/events.hpp>
#include <event-broker/topics.hpp>
WindowController::WindowController(World* world, EventBroker* broker):
    m_Window(world),
    m_EventBroker(broker) {
    m_Window.init();
}
Window& WindowController::getWindow() {
    return m_Window;
}

void WindowController::start() {
    bool shouldExit = false;
    SDL_Event event;
    while (!shouldExit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            // std::cout << "Received an event: " << event.type << "\n";
            switch (event.type)
            {
            case SDL_QUIT:
                shouldExit = true;
                break;
            case SDL_WINDOW_MOUSE_FOCUS:
                m_EventBroker->publish(MOUSE_EVENTS_TOPIC, new MouseEvent {
                    type: MOUSE_ENTERED,
                    point: { x : event.motion.x, y: event.motion.y }
                });
                break;
            case SDL_MOUSEBUTTONDOWN:
                m_EventBroker->publish(MOUSE_EVENTS_TOPIC,  new MouseEvent {
                    type: MOUSE_CLICKED,
                    point: { x : event.motion.x, y: event.motion.y }
                });
                break;
            }
        }
        m_Window.update();
        SDL_Delay(1000 / 10);
    }
}