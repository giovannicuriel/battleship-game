#include <iostream>
#include "event-broker.hpp"

EventBroker::EventBroker(SubscriptionHandlerFactory * factory):
    m_SubscriptionHandlers(),
    m_SubscriptionHandlerFactory(factory) {
}

EventBroker::~EventBroker() {
    for (auto& [topic, handler]: m_SubscriptionHandlers) {
        std::cout << "Stopping subscription handler for topic " << topic << "\n";
        delete handler;
    }
}

SubscriptionHandler* EventBroker::getOrCreateHandler(Topic topic) {
    if (!m_SubscriptionHandlers.contains(topic)) {
        m_SubscriptionHandlers[topic] = m_SubscriptionHandlerFactory->build();
    }
    return m_SubscriptionHandlers[topic];
}

void EventBroker::subscribe(Topic topic, Subscriber* subscriber) {
    // TODO: change this pointer to an unique pointer, so that its reference
    // now will belong to event broker.
    if (subscriber == nullptr) {
        return;
    }

    SubscriptionHandler* handler = getOrCreateHandler(topic);
    handler->addSubscriber(subscriber);
}

void EventBroker::publish(Topic topic, Event* event) {
    if (m_SubscriptionHandlers.contains(topic)) {
        m_SubscriptionHandlers[topic]->enqueueEvent(event);
    }
}

