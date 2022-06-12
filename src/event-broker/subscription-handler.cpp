#include <iostream>
#include <unistd.h>
#include "subscription-handler.hpp"

void SubscriptionHandlerImpl::eventLoop(SubscriptionHandlerImpl* handler) {
    handler->isRunning = true;
    while (handler->isRunning) {
        Event* event = handler->dequeueEvent();
        if (event == nullptr) {
            continue;
        }
        for (auto& s: handler->subscribers) {
            s->processEvent(event);
        }
        delete event;
    }
}

void SubscriptionHandlerImpl::stop() {
    if (isRunning == false) { return; }
    isRunning = false;
    semaphore.release();
    std::cout << "Stopping thread.\n";
    thread.join();
    std::cout << "Thread stopped.\n";
}

SubscriptionHandlerImpl::SubscriptionHandlerImpl():
    subscribers(),
    queue(),
    mutex(),
    semaphore(0) {
    isRunning = false;
    thread = std::thread(SubscriptionHandlerImpl::eventLoop, this);
    while (!isRunning) {
        usleep(100);
    }
}

SubscriptionHandlerImpl::~SubscriptionHandlerImpl() {
    stop();
}

void SubscriptionHandlerImpl::enqueueEvent(Event* event) {
    mutex.lock();
    queue.push(event);
    mutex.unlock();
    semaphore.release();
}

Event* SubscriptionHandlerImpl::dequeueEvent() {
    semaphore.acquire();
    mutex.lock();
    Event* event = nullptr;
    if (queue.size() != 0) {
        event = queue.front();
        queue.pop();
    }
    mutex.unlock();
    return event;
}

void SubscriptionHandlerImpl::addSubscriber(Subscriber* subscriber) {
    subscribers.push_back(subscriber);
}

void SubscriptionHandlerImpl::processEvent(Event* event) {
    for (auto& s: subscribers) {
        s->processEvent(event);
    }
}
