#ifndef __EVENT_BROKER_HPP__
#define __EVENT_BROKER_HPP__

#include <string>
#include <map>
#include "events.hpp"
#include "subscriber.hpp"
#include "subscription-handler.hpp"
#include "subscription-handler-factory.hpp"

typedef std::string Topic;

class EventBroker {
protected:
    std::map<Topic, SubscriptionHandler*> m_SubscriptionHandlers;
    SubscriptionHandlerFactory* m_SubscriptionHandlerFactory;

    SubscriptionHandler* getOrCreateHandler(Topic topic);
public:
    EventBroker(
        SubscriptionHandlerFactory * factory
    );
    virtual ~EventBroker();

    void subscribe(Topic topic, Subscriber* subscriber);
    void publish(Topic topic, Event* event);
};


#endif // __EVENT_BROKER_HPP__
