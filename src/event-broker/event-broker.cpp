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

void EventBroker::subscribe(Topic topic, Subscriber* subscriber) {
    if (!m_SubscriptionHandlers.contains(topic)) {
        m_SubscriptionHandlers[topic] = m_SubscriptionHandlerFactory->build();
    }
    m_SubscriptionHandlers[topic]->addSubscriber(subscriber);
}

void EventBroker::publish(Topic topic, Event* event) {
    if (m_SubscriptionHandlers.contains(topic)) {
        m_SubscriptionHandlers[topic]->enqueueEvent(event);
    }
}

