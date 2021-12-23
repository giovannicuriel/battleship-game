#include "../src/event-broker/subscription-handler-factory.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::_;


TEST(SubscriptionHandlerFactoryTest, SuccessfullyBuildAHandler) {
    SubscriptionHandlerFactoryImpl factory;
    auto result = factory.build();

    EXPECT_NE(result, nullptr);
}
