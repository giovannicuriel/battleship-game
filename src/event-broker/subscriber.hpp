#ifndef __SUBSCRIBER_HPP__
#define __SUBSCRIBER_HPP__

#include "events.hpp"

class Subscriber {
public:
    virtual void processEvent(Event* event) = 0;
};


#endif // __SUBSCRIBER_HPP__
