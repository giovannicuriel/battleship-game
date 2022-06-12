#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../mocks/gui/world/mock-world.hpp"
#include "../mocks/gui/mock-window.hpp"
#include "../mocks/adapters/mock-sdl-adapter.hpp"
#include "../mocks/event-broker/mock-event-broker.hpp"
#include <controller/window-controller.hpp>

using ::testing::_;

TEST(WindowControllerTest, ShouldBuildAWindowController) {
    MockWorld mockWorld;
    MockEventBroker mockBroker;
    MockSdlAdapter mockAdapter;
    EXPECT_CALL(mockAdapter, createWindow("SDL Tutorial", _))
        .Times(1);
    WindowController controller(&mockWorld, &mockBroker, &mockAdapter);
}
