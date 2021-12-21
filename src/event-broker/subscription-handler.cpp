#include <iostream>
#include "subscription-handler.hpp"

void SubscriptionHandlerImpl::eventLoop(SubscriptionHandlerImpl* handler) {
    while (handler->isRunning) {
        handler->semaphore.acquire();
        Event* event = handler->dequeueEvent();
        if (event == nullptr) { continue; }
        for (auto& s: handler->subscribers) {
            s->processEvent(event);
        }
    }
}

SubscriptionHandlerImpl::SubscriptionHandlerImpl():
    subscribers(),
    queue(),
    mutex(),
    semaphore(0),
    isRunning(true) {
    thread = std::thread(SubscriptionHandlerImpl::eventLoop, this);
}

SubscriptionHandlerImpl::~SubscriptionHandlerImpl() {
    isRunning = false;
    semaphore.release();
    std::cout << "Stopping thread.\n";
    thread.join();
    std::cout << "Thread stopped.\n";
}

void SubscriptionHandlerImpl::enqueueEvent(Event* event) {
    mutex.lock();
    queue.push(event);
    semaphore.release();
    mutex.unlock();
}

Event* SubscriptionHandlerImpl::dequeueEvent() {
    mutex.lock();
    Event* event = queue.front();
    queue.pop();
    mutex.unlock();
    return event;
}

void SubscriptionHandlerImpl::addSubscriber(Subscriber* subscriber) {
    subscribers.push_back(subscriber);
}