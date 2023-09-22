#include <iostream>
#include <adapters/sdl-adapter-impl.hpp>
#include <event-broker/topics.hpp>
#include <event-broker/events.hpp>
#include <types.hpp>
#include <unistd.h>

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
       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE
    );

    SDL_SetRenderDrawBlendMode(this->m_Renderer, SDL_BLENDMODE_BLEND);
    /* Create texture for display */
    this->display = SDL_CreateTexture(this->m_Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, area.w, area.h);

    SDL_SetRenderTarget(this->m_Renderer, this->display);
};

void SdlAdapterImpl::clearRenderer() {
    SDL_SetRenderDrawColor(this->m_Renderer, 0xFF, 0xFF, 0xff, 0xFF);
    SDL_RenderClear(this->m_Renderer);
}

void SdlAdapterImpl::render() {
    SDL_SetRenderTarget(this->m_Renderer, NULL);
    SDL_RenderCopy(this->m_Renderer, this->display, NULL, NULL);
    SDL_RenderPresent(this->m_Renderer);
    SDL_SetRenderTarget(this->m_Renderer, this->display);
}

void SdlAdapterImpl::refresh(void* obj) {
    SdlAdapterImpl *reference = (SdlAdapterImpl *)obj;
    RefreshWindowEvent refreshEvent;

    int lastTicks = SDL_GetTicks();
    int currTicks = 0;
    int diff = 0;
    int desiredFps = 27;
    while (!reference->shouldExit) {
        currTicks = SDL_GetTicks();
        diff = currTicks - lastTicks;
        if (diff < 1000 / desiredFps) {
            SDL_Delay(1);
        } else {
            lastTicks = SDL_GetTicks();
            reference->m_EventBroker->publishSync(SYSTEM_EVENTS_TOPIC, &refreshEvent);
        }
    }
}

void SdlAdapterImpl::start() {
    this->shouldExit = false;
    SDL_Event event;
    MouseEvent mouseEvent;
    std::thread refresherThread = std::thread(SdlAdapterImpl::refresh, this);
    while (!shouldExit) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
            case SDL_QUIT:
                this->shouldExit = true;
                break;
            case SDL_WINDOW_MOUSE_FOCUS:
                mouseEvent.type = MOUSE_ENTERED;
                mouseEvent.point.x = event.motion.x;
                mouseEvent.point.y = event.motion.y;
                m_EventBroker->publish(MOUSE_EVENTS_TOPIC, &mouseEvent);
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseEvent.type = MOUSE_CLICKED;
                mouseEvent.point.x = event.motion.x;
                mouseEvent.point.y = event.motion.y;
                m_EventBroker->publish(MOUSE_EVENTS_TOPIC, &mouseEvent);
                break;
            }
        }
        SDL_Delay(100);
    }
    refresherThread.join();
}

void SdlAdapterImpl::setRenderDrawColor(Color color) {
    SDL_SetRenderDrawColor(this->m_Renderer, color.r, color.g, color.b, color.a);
}
void SdlAdapterImpl::renderFillRect(Area area) {
    SDL_Rect rect { x: area.x, y: area.y, w: area.w, h: area.h };
    SDL_RenderFillRect(this->m_Renderer, &rect);
}
