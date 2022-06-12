#include <controller/window-controller.hpp>
#include <controller/board-controller.hpp>
#include <controller/game-controller.hpp>
#include <gui/world/world.hpp>
#include <event-broker/event-broker.hpp>
#include <event-broker/subscription-handler-factory.hpp>
#include <event-broker/topics.hpp>
#include <adapters/sdl-adapter-impl.hpp>

int main(void) {
    SubscriptionHandlerFactoryImpl factory;
    EventBroker broker(&factory);
    World world;
    SdlAdapterImpl sdl(&broker);
    WindowController app(&world, &broker, &sdl);
    GameController gameController(&broker);
    BoardController boardController(&broker);

    boardController.addTilesTo(&app.getWindow());
    boardController.start();
    app.start();
    return 0;
}