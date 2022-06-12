#include <gtest/gtest.h>
#include <event-broker/events.hpp>

TEST(EventsTest, ShouldBuild) {
    EventFactory factory;

    Event* emptyEvent = factory.buildEmptyEvent();
    Event* mouseEvent = factory.buildMouseEvent(MOUSE_ENTERED, {x: 0, y: 0});
    Event* gameEvent = factory.buildGameEvent(GAME_OVER);
    Event* simpleEvent = factory.buildSimpleEvent("this is a test");
    Event* refreshWindowEvent = factory.buildRefreshWindowEvent();

    EXPECT_NE(emptyEvent, nullptr);
    EXPECT_NE(mouseEvent, nullptr);
    EXPECT_NE(gameEvent, nullptr);
    EXPECT_NE(simpleEvent, nullptr);
    EXPECT_NE(refreshWindowEvent, nullptr);
}