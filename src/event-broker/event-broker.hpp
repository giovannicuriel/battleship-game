#ifndef __EVENT_BROKER_HPP__
#define __EVENT_BROKER_HPP__

#include <string>
#include <queue>
#include <list>
#include <mutex>
#include <map>
#include <thread>
#include <semaphore>
#include "events.hpp"
#include "subscriber.hpp"

typedef std::string Topic;

class SubscriptionHandler {
public:
    std::list<Subscriber*> subscribers;
    std::queue<Event*> queue;
    std::mutex mutex;
    std::thread thread;
    std::counting_semaphore<10> semaphore;
    bool isRunning;

    static void eventLoop(SubscriptionHandler* handler);

public:
    SubscriptionHandler();
    virtual ~SubscriptionHandler();
    void enqueueEvent(Event *event);
    Event * dequeueEvent();
};

class EventBroker {
protected:
    std::map<Topic, SubscriptionHandler*> m_SubscriptionHandlers;
public:
    EventBroker();
    virtual ~EventBroker();

    void subscribe(Topic topic, Subscriber* subscriber);
    void publish(Topic topic, Event* event);
};


#endif // __EVENT_BROKER_HPP__
