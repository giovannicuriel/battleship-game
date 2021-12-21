#include "subscription-handler-factory.hpp"

SubscriptionHandler* SubscriptionHandlerFactoryImpl::build() {
    return new SubscriptionHandlerImpl();
}
