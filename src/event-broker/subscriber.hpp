#ifndef __SUBSCRIBER_HPP__
#define __SUBSCRIBER_HPP__

class Subscriber {
public:
    Subscriber();
    virtual ~Subscriber();

    virtual void notify(const char* event, void* data) = 0;
};


#endif // __SUBSCRIBER_HPP__
