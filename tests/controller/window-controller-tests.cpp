#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../mocks/gui/world/mock-world.hpp"
#include "../mocks/gui/mock-window.hpp"
#include "../mocks/adapters/mock-sdl-adapter.hpp"
#include "../mocks/event-broker/mock-event-broker.hpp"
#include <controller/window-controller.hpp>
#include <event-broker/topics.hpp>

using ::testing::_;

class ChildWindowController: public WindowController {
public:
    ChildWindowController(
        World* world,
        EventBroker* broker,
        SdlAdapter* sdlAdapter
    ): WindowController(world, broker, sdlAdapter) {};
};

TEST(WindowControllerTest, ShouldBuildAWindowController) {
    MockWorld mockWorld;
    MockEventBroker mockBroker;
    MockSdlAdapter mockAdapter;
    EXPECT_CALL(mockAdapter, createWindow("SDL Tutorial", _))
        .Times(2);
    WindowController controller(&mockWorld, &mockBroker, &mockAdapter);
    ChildWindowController childController(&mockWorld, &mockBroker, &mockAdapter);

    auto window = controller.getWindow();
}

TEST(WindowControllerTest, ShouldStartCorrectly) {
    MockWorld mockWorld;
    MockEventBroker mockBroker;
    MockSdlAdapter mockAdapter;
    WindowController controller(&mockWorld, &mockBroker, &mockAdapter);

    EXPECT_CALL(mockAdapter, start())
        .Times(1);
    EXPECT_CALL(mockBroker, subscribe(SYSTEM_EVENTS_TOPIC, &controller))
        .Times(1);

    controller.start();
}

TEST(WindowControllerTest, ShouldUpdateWindow) {
    MockWorld mockWorld;
    MockEventBroker mockBroker;
    MockSdlAdapter mockAdapter;
    WindowController controller(&mockWorld, &mockBroker, &mockAdapter);

    EXPECT_CALL(mockAdapter, clearRenderer())
        .Times(1);
    EXPECT_CALL(mockAdapter, render())
        .Times(1);
    EXPECT_CALL(mockWorld, draw)
        .Times(1);

    controller.processEvent(nullptr);
}
