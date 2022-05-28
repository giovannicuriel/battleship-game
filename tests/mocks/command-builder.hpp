#ifndef __MOCK_COMMAND_BUILDER_HPP__
#define __MOCK_COMMAND_BUILDER_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockCliCommandBuilder: public CliCommandBuilder {
public:
    MockCliCommandBuilder(): CliCommandBuilder(nullptr, nullptr, nullptr) {};
    MOCK_METHOD(CliCommandNode, buildCommand, (CommandKey), (override));
};

#endif // __MOCK_COMMAND_BUILDER_HPP__