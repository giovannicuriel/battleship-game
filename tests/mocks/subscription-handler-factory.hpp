#ifndef __MOCK_SUBSCRIPTION_HANDLER_FACTORY_HPP__
#define __MOCK_SUBSCRIPTION_HANDLER_FACTORY_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockSubscriptionHandlerFactory: public SubscriptionHandlerFactory {
public:
    MOCK_METHOD(SubscriptionHandler*, build, (), (override));
    ~MockSubscriptionHandlerFactory() { }
};

#endif // __MOCK_SUBSCRIPTION_HANDLER_FACTORY_HPP__
