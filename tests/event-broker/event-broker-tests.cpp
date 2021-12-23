#include "../src/event-broker/event-broker.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "mocks/subscription-handler-factory.hpp"
#include "mocks/subscription-handler.hpp"
#include "mocks/subscriber.hpp"

using ::testing::Return;
using ::testing::_;


TEST(EventBrokerTest, SuccessfullyCreatesSubscriptions) {
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
