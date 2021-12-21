#ifndef __EVENT_BROKER_HPP__
#define __EVENT_BROKER_HPP__

class EventBroker {
public:
    EventBroker();
    virtual ~EventBroker();

    void subscribe(const char* event, void (*callback)(void*));
    void publish(const char* event, void* data);
}


#endif // __EVENT_BROKER_HPP__
