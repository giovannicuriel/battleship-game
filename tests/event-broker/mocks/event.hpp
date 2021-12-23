#ifndef __MOCK_EVENT_HPP__
#define __MOCK_EVENT_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/event-broker/events.hpp"

class MockEvent: public Event { };

#endif // __MOCK_EVENT_HPP__
