#include <gui/window.hpp>

Window::Window(World *world, SdlAdapter* adapter):
    m_World(world),
    m_Sdl(adapter) {
}

void Window::init() {
    // Maybe throw an exception here?
    if (m_Sdl->init() < 0) { return; }
    m_Sdl->createWindow("SDL Tutorial", Area { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
}

void Window::update() {
    // Maybe this could be condensed as just one 'render' call. Passing a lambda
    // with m_World->draw could make this possible.
    m_Sdl->clearRenderer();
    m_World->draw();
    m_Sdl->render();
}

void Window::addObject(WorldObject* worldObj) {
    m_World->addWorldObject(worldObj);
}
