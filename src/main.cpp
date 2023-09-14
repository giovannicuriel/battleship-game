#include <controller/window-controller.hpp>
// #include <controller/board-controller.hpp>
// #include <controller/game-controller.hpp>
// #include <gui/world/world.hpp>
#include <event-broker/event-broker.hpp>
#include <event-broker/subscription-handler-factory.hpp>
#include <event-broker/topics.hpp>
#include <adapters/sdl-adapter-impl.hpp>
// #include <logic/minefield/minefield.hpp>
#include <event-broker/events.hpp>

int main(void) {
    // Event-related classes
    SubscriptionHandlerFactoryImpl factory;
    EventBroker broker(&factory);

    // // Game related classes
    SdlAdapterImpl sdl(&broker);
    WindowController app(&broker, &sdl);
    // World world;
    // GameController gameController(&broker);
    // Field field;
    // BoardControllerConfig config = {
    //     {8, 8},
    //     10,
    //     {50, 50}
    // };

    // EventFactory eventFactory;
    // BoardController boardController(
    //     &broker,
    //     &field,
    //     config,
    //     &eventFactory
    // );

    // boardController.addTilesTo(&app.getWindow());
    // gameController.start();
    // boardController.start();
    app.start();
    return 0;
}