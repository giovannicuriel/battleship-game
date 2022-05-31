#include "gui/window.hpp"

Window::Window(World *world):
    m_Window(nullptr),
    m_ScreenSurface(nullptr),
    m_Renderer(nullptr),
    m_World(world)
{

}

Window::~Window()
{
    SDL_DestroyWindow(this->m_Window);
    SDL_DestroyRenderer(this->m_Renderer);
    SDL_Quit();
}

void Window::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Could not initialize video: " << SDL_GetError() << "\n";
        return;
    }

    this->m_Window = SDL_CreateWindow("SDL Tutorial",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);

    if (this->m_Window == nullptr)
    {
        std::cerr << "Could not create window: " << SDL_GetError() << "\n";
        return;
    }

    this->m_Renderer = SDL_CreateRenderer(this->m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::update()
{
    SDL_SetRenderDrawColor(this->m_Renderer, 0xFF, 0xFF, 0xff, 0xFF);
    SDL_RenderClear(this->m_Renderer);
    m_World->draw();
    SDL_RenderPresent(this->m_Renderer);
}

void Window::addObject(WorldObject* worldObj) {
    m_World->addWorldObject(worldObj);
}