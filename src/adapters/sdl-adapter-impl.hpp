#ifndef __ADAPTERS_SDL_ADAPTER_IMPL_HPP__
#define __ADAPTERS_SDL_ADAPTER_IMPL_HPP__

#include <SDL.h>
#include <adapters/sdl-adapter.hpp>
#include <event-broker/event-broker.hpp>
#include <types.hpp>

class SdlAdapterImpl: public SdlAdapter {
protected:
    SDL_Renderer* m_Renderer;
    SDL_Window* m_Window;
    EventBroker* m_EventBroker;
    SDL_Texture *display;
    bool shouldExit;
    static void refresh(void* obj);
public:
    SdlAdapterImpl(EventBroker* eventBroker);
    virtual ~SdlAdapterImpl();
    int init() override;
    void start() override;
    void createWindow(const char *title, Area area) override;
    void clearRenderer() override;
    void render() override;
    void setRenderDrawColor(Color color) override;
    void renderFillRect(Area rect) override;
};

#endif // __ADAPTERS_SDL_ADAPTER_IMPL_HPP__
