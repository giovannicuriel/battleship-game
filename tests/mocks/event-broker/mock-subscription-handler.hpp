#ifndef __MOCK_SUBSCRIPTION_HANDLER_HPP__
#define __MOCK_SUBSCRIPTION_HANDLER_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockSubscriptionHandler: public SubscriptionHandler {
public:
    MOCK_METHOD(void, enqueueEvent, (Event *event), (override));
    MOCK_METHOD(Event *, dequeueEvent, (), (override));
    MOCK_METHOD(void, processEvent, (Event* event), (override));
    MOCK_METHOD(void, addSubscriber, (Subscriber * subscriber), (override));
    ~MockSubscriptionHandler() { }
};

#endif // __MOCK_SUBSCRIPTION_HANDLER_HPP__
