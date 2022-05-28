#include "../src/event-broker/event-broker.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../mocks/subscription-handler-factory.hpp"
#include "../mocks/subscription-handler.hpp"
#include "../mocks/subscriber.hpp"
#include "../mocks/event.hpp"

using ::testing::Return;
using ::testing::_;


TEST(EventBrokerTest, SuccessfullyCreateAndDestroyObject) {
    EventBroker* broker = new EventBroker { nullptr };
    delete broker;
}

TEST(EventBrokerTest, SuccessfullyCreateSubscriptions) {
    MockSubscriptionHandler* mockSubscriptionHandler = new MockSubscriptionHandler();
    MockSubscriptionHandlerFactory mockFactory;
    MockSubscriber mockSubscriber;

    EventBroker broker { &mockFactory };

    EXPECT_CALL(*mockSubscriptionHandler, addSubscriber(_))
        .Times(1);
    EXPECT_CALL(mockFactory, build())
        .Times(1)
        .WillRepeatedly(Return(mockSubscriptionHandler));

    Topic t("sample-topic");
    broker.subscribe(t, &mockSubscriber);
}

TEST(EventBrokerTest, ShouldCreateOnlyOneHandlerPerTopic) {
    MockSubscriptionHandler* mockSubscriptionHandler = new MockSubscriptionHandler();
    MockSubscriptionHandlerFactory mockFactory;
    MockSubscriber mockSubscriber;

    EventBroker broker { &mockFactory };

    EXPECT_CALL(*mockSubscriptionHandler, addSubscriber(_))
        .Times(3);
    EXPECT_CALL(mockFactory, build())
        .Times(1)
        .WillRepeatedly(Return(mockSubscriptionHandler));

    Topic t("sample-topic");
    broker.subscribe(t, &mockSubscriber);
    broker.subscribe(t, &mockSubscriber);
    broker.subscribe(t, &mockSubscriber);
}

TEST(EventBrokerTest, ShouldNotCreateSubscriptionForNullSubscriber) {
    MockSubscriptionHandlerFactory mockFactory;

    EventBroker broker { &mockFactory };

    EXPECT_CALL(mockFactory, build())
        .Times(0);

    Topic t("sample-topic");
    broker.subscribe(t, nullptr);
}


TEST(EventBrokerTest, ShouldSuccessfullyPublish) {
    MockSubscriptionHandler* mockSubscriptionHandler = new MockSubscriptionHandler();
    MockSubscriptionHandlerFactory mockFactory;
    MockSubscriber mockSubscriber;
    MockEvent mockEvent;

    EventBroker broker { &mockFactory };

    EXPECT_CALL(*mockSubscriptionHandler, addSubscriber(_))
        .Times(1);
    EXPECT_CALL(mockFactory, build())
        .Times(1)
        .WillRepeatedly(Return(mockSubscriptionHandler));
    Topic t("sample-topic");
    broker.subscribe(t, &mockSubscriber);
    broker.publish(t, &mockEvent);
}

