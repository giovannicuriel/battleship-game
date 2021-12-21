#include <iostream>
#include "event-broker.hpp"

void SubscriptionHandler::eventLoop(SubscriptionHandler* handler) {
    while (handler->isRunning) {
        handler->semaphore.acquire();
        Event* event = handler->dequeueEvent();
        if (event == nullptr) { continue; }
        for (auto& s: handler->subscribers) {
            s->processEvent(event);
        }
    }
}

SubscriptionHandler::SubscriptionHandler():
    subscribers(),
    queue(),
    mutex(),
    semaphore(0),
    isRunning(true) {
    thread = std::thread(SubscriptionHandler::eventLoop, this);
}

SubscriptionHandler::~SubscriptionHandler() {
    isRunning = false;
    semaphore.release();
    std::cout << "Stopping thread.\n";
    thread.join();
    std::cout << "Thread stopped.\n";
}

EventBroker::EventBroker():
    m_SubscriptionHandlers() {
}

EventBroker::~EventBroker() {
    for (auto& [topic, handler]: m_SubscriptionHandlers) {
        std::cout << "Stopping subscription handler for topic " << topic << "\n";
        delete handler;
    }

}

void EventBroker::subscribe(Topic topic, Subscriber* subscriber) {
    if (!m_SubscriptionHandlers.contains(topic)) {
        m_SubscriptionHandlers[topic] = new SubscriptionHandler();
    }
    m_SubscriptionHandlers[topic]->subscribers.push_back(subscriber);
}

void EventBroker::publish(Topic topic, Event* event) {
    if (m_SubscriptionHandlers.contains(topic)) {
        m_SubscriptionHandlers[topic]->enqueueEvent(event);
    }
}

void SubscriptionHandler::enqueueEvent(Event* event) {
    mutex.lock();
    queue.push(event);
    semaphore.release();
    mutex.unlock();
}

Event* SubscriptionHandler::dequeueEvent() {
    mutex.lock();
    Event* event = queue.front();
    queue.pop();
    mutex.unlock();
    return event;
}