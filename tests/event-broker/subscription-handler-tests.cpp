#include "../src/event-broker/subscription-handler.hpp"
#include "../src/event-broker/subscription-handler-factory.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../mocks/event-broker/mock-subscription-handler-factory.hpp"
#include "../mocks/event-broker/mock-subscription-handler.hpp"
#include "../mocks/event-broker/mock-subscriber.hpp"
#include "../mocks/event-broker/mock-event.hpp"

using ::testing::Return;
using ::testing::_;

TEST(SubscriptionHandlerTest, ShouldSuccessfullyCreateAndDestroyObject) {
    SubscriptionHandlerImpl* handler = new SubscriptionHandlerImpl();
    delete handler;
}

TEST(SubscriptionHandlerTest, ShouldSuccessfullyAddASubscriber) {
    SubscriptionHandlerImpl handler;
    MockSubscriber mockSubscriber;

    handler.addSubscriber(&mockSubscriber);
}

TEST(SubscriptionHandlerTest, ShouldSuccessfullyProcessAnEvent) {
    SubscriptionHandlerImpl handler;
    MockSubscriber mockSubscriber;
    MockEvent* event = new MockEvent();

    EXPECT_CALL(mockSubscriber, processEvent(_))
        .Times(1);
    handler.addSubscriber(&mockSubscriber);
    handler.enqueueEvent(event);
    handler.stop();
}

TEST(SubscriptionHandlerTest, ShouldSuccessfullyProcessAnEventSynchronously) {
    SubscriptionHandlerImpl handler;
    MockSubscriber mockSubscriber;
    MockEvent* event = new MockEvent();

    EXPECT_CALL(mockSubscriber, processEvent(_))
        .Times(1);
    handler.addSubscriber(&mockSubscriber);
    handler.processEvent(event);
    handler.stop();
}

TEST(SubscriptionHandlerTest, ShouldSuccessfullyProcessANullEvent) {
    SubscriptionHandlerImpl handler;
    MockSubscriber mockSubscriber;

    EXPECT_CALL(mockSubscriber, processEvent(_))
        .Times(0);
    handler.addSubscriber(&mockSubscriber);
    handler.enqueueEvent(nullptr);
    handler.stop();
}
