#ifndef __MOCK_EVENT_HPP__
#define __MOCK_EVENT_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/event-broker/events.hpp"

class MockEventFactory: public EventFactory {
public:
    MOCK_METHOD((Event*), buildEmptyEvent, (), (override));
    MOCK_METHOD((Event*), buildMouseEvent, (MouseEventType type, Point point), (override));
    MOCK_METHOD((Event*), buildGameEvent, (GameEventType type), (override));
    MOCK_METHOD((Event*), buildSimpleEvent, (std::string event), (override));
    MOCK_METHOD((Event*), buildRefreshWindowEvent, (), (override));
};

class MockEvent: public Event {
public:
    ~MockEvent() { }
};

std::ostream& operator<<(std::ostream& out, MockEvent& ev) {
    out << "mock event\n";
    return out;
}

#endif // __MOCK_EVENT_HPP__
