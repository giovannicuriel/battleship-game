#ifndef __SUBSCRIPTION_HANDLER_HPP__
#define __SUBSCRIPTION_HANDLER_HPP__

#include <list>
#include <queue>
#include <mutex>
#include <thread>
#include <semaphore>

#include "events.hpp"
#include "subscriber.hpp"

class SubscriptionHandler  {
public:
    virtual ~SubscriptionHandler() { };
    virtual void enqueueEvent(Event *event) = 0;
    virtual Event * dequeueEvent() = 0;
    virtual void processEvent(Event* event) = 0;
    virtual void addSubscriber(Subscriber * subscriber) = 0;
};

class SubscriptionHandlerImpl: public SubscriptionHandler {
protected:
    std::list<Subscriber*> subscribers;
    std::queue<Event*> queue;
    std::mutex mutex;
    std::thread thread;
    std::counting_semaphore<10> semaphore;
    bool isRunning;

    static void eventLoop(SubscriptionHandlerImpl* handler);
public:
    SubscriptionHandlerImpl();
    virtual ~SubscriptionHandlerImpl();
    void stop();
    void enqueueEvent(Event *event);
    Event * dequeueEvent();
    void processEvent(Event* event) override;
    void addSubscriber(Subscriber * subscriber);
};

#endif // __SUBSCRIPTION_HANDLER_HPP__