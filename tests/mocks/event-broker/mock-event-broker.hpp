#ifndef __MOCK_EVENT_BROKER_HPP__
#define __MOCK_EVENT_BROKER_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <event-broker/event-broker.hpp>

class MockEventBroker: public EventBroker {
public:
    MockEventBroker(): EventBroker(nullptr) {}
    MOCK_METHOD(void, subscribe, (Topic topic, Subscriber* subscriber), (override));
    MOCK_METHOD(void, publish, (Topic topic, Event* event), (override));
    MOCK_METHOD(void, publishSync, (Topic topic, Event* event), (override));
};

#endif // __MOCK_EVENT_BROKER_HPP__p