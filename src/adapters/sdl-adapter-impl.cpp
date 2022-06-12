#include <iostream>
#include <adapters/sdl-adapter-impl.hpp>
#include <event-broker/topics.hpp>
#include <event-broker/events.hpp>
#include <types.hpp>

SdlAdapterImpl::SdlAdapterImpl(EventBroker* eventBroker):
    m_EventBroker(eventBroker) {
}

SdlAdapterImpl::~SdlAdapterImpl() {
    SDL_DestroyWindow(this->m_Window);
    SDL_DestroyRenderer(this->m_Renderer);
    SDL_Quit();
}

int SdlAdapterImpl::init() {
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) {
        std::cerr << "Could not initialize video: " << SDL_GetError() << "\n";
    };
    return ret;
}

void SdlAdapterImpl::createWindow(const char *title, Area area) {
    m_Window = SDL_CreateWindow(
        title,
        area.x > 0 ? area.x : SDL_WINDOWPOS_CENTERED,
        area.y > 0 ? area.y : SDL_WINDOWPOS_CENTERED,
        area.w,
        area.h,
        SDL_WINDOW_SHOWN
    );

    if (this->m_Window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError() << "\n";
        return;
    }

    this->m_Renderer = SDL_CreateRenderer(
       this->m_Window,
       -1,
       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
};

void SdlAdapterImpl::clearRenderer() {
    SDL_SetRenderDrawColor(this->m_Renderer, 0xFF, 0xFF, 0xff, 0xFF);
    SDL_RenderClear(this->m_Renderer);
}

void SdlAdapterImpl::render() {
    SDL_RenderPresent(this->m_Renderer);
}

void SdlAdapterImpl::start() {
    bool shouldExit = false;
    SDL_Event event;
    while (!shouldExit) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
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
                m_EventBroker->publish(MOUSE_EVENTS_TOPIC, new MouseEvent {
                    type: MOUSE_CLICKED,
                    point: { x : event.motion.x, y: event.motion.y }
                });
                break;
            }
        }
        m_EventBroker->publishSync(SYSTEM_EVENTS_TOPIC, new RefreshWindowEvent());
        SDL_Delay(1000 / 10);
    }
}

void SdlAdapterImpl::setRenderDrawColor(Color color) {
    SDL_SetRenderDrawColor(this->m_Renderer, color.r, color.g, color.b, color.a);
}
void SdlAdapterImpl::renderFillRect(Area area) {
    SDL_Rect rect { x: area.x, y: area.y, w: area.w, h: area.h };
    SDL_RenderFillRect(this->m_Renderer, &rect);
}
