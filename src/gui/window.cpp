#include <gui/window.hpp>

Window::Window(SdlAdapter* adapter):
    m_Sdl(adapter) {
}

void Window::init() {
    if (m_Sdl->init() < 0) { return; }
    m_Sdl->createWindow("SDL Tutorial", Area { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
}

void Window::update() {
    // Maybe this could be condensed as just one 'render' call. Passing a lambda
    // with m_World->draw could make this possible.
    m_Sdl->clearRenderer();
    m_Sdl->render();
}
