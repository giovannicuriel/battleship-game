#include "../src/event-broker/event-broker.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::_;

class MockSubscriptionHandlerFactory: public SubscriptionHandlerFactory {
public:
    MOCK_METHOD(SubscriptionHandler*, build, (), (override));
    ~MockSubscriptionHandlerFactory() { }
};

class MockSubscriptionHandler: public SubscriptionHandler {
public:
    MOCK_METHOD(void, enqueueEvent, (Event *event), (override));
    MOCK_METHOD(Event *, dequeueEvent, (), (override));
    MOCK_METHOD(void, addSubscriber, (Subscriber * subscriber), (override));
    ~MockSubscriptionHandler() { }
};

class MockSubscriber: public Subscriber {
public:
    MOCK_METHOD(void, processEvent, (Event *), (override));
    ~MockSubscriber() { }
};


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
