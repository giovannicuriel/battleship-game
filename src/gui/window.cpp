#include <gui/window.hpp>

Window::Window(SdlAdapter* adapter):
    m_Sdl(adapter) {
}

void Window::init() {
    if (m_Sdl->init() < 0) { return; }
    m_Sdl->createWindow("SDL Tutorial", Area { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
    m_Sdl->clearRenderer();
}

void Window::update() {
    // Maybe this could be condensed as just one 'render' call. Passing a lambda
    // with m_World->draw could make this possible.

    static Color color = {0, 0, 0, 255};
    static bool isAscendingColor = true;
    static uint8_t colorStep = 2;
    static int32_t x = 0;
    static int32_t y = 0;
    static int32_t xStep = 20;
    static int32_t yStep = 5;

    color += { 0, 0, colorStep, 0};
    if (color.b == 255) {
      color += { 0, colorStep, 0, 0};
      color.b = 0;
    }
    if (color.g == 255) {
      color += { colorStep, 0, 0, 0};
      color.g = 0;
    }
    if (color.r == 255) {
      color = {0, 0, 0, 255};
    }

    x += xStep;
    y += yStep;
    if ((x + 50 > SCREEN_WIDTH && xStep > 0) || (x < 0 && xStep < 0)) {
      xStep *= -1;
    }
    if ((y + 50 > SCREEN_WIDTH && yStep > 0) || (y < 0 && yStep < 0)) {
      yStep *= -1;
    }

    Color white = {0, 0, 0, 25};
    Area area = {x, y, 50, 50};
    m_Sdl->setRenderDrawColor(color);
    m_Sdl->renderFillRect(area);
    m_Sdl->render();
}
