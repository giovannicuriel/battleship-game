#ifndef __MOCK_SUBSCRIBER_HPP__
#define __MOCK_SUBSCRIBER_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockSubscriber: public Subscriber {
public:
    MOCK_METHOD(void, processEvent, (Event *), (override));
    ~MockSubscriber() { }
};

#endif // __MOCK_SUBSCRIBER_HPP__
