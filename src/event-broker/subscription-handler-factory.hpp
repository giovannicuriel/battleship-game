#ifndef __SUBSCRIPTION_HANDLER_FACTORY_HPP__
#define __SUBSCRIPTION_HANDLER_FACTORY_HPP__

#include "subscription-handler.hpp"

class SubscriptionHandlerFactory {
public:
    virtual SubscriptionHandler* build() = 0;
};

class SubscriptionHandlerFactoryImpl: public SubscriptionHandlerFactory {
public:
    SubscriptionHandler* build();
};

#endif //__SUBSCRIPTION_HANDLER_FACTORY_HPP__
