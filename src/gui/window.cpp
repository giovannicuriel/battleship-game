#include "gui/window.hpp"

Window::Window(World *world)
{
    this->window = nullptr;
    this->screenSurface = nullptr;
    this->renderer = nullptr;
    this->world = world;
}

Window::~Window()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}

void Window::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Could not initialize video: " << SDL_GetError() << "\n";
        return;
    }

    this->window = SDL_CreateWindow("SDL Tutorial",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);

    if (this->window == nullptr)
    {
        std::cerr << "Could not create window: " << SDL_GetError() << "\n";
        return;
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::update()
{
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xff, 0xFF);
    SDL_RenderClear(this->renderer);
    world->draw();
    SDL_RenderPresent(this->renderer);
}
