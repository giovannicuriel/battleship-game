#ifndef __MOCK_CLI_COMMAND_HPP__
#define __MOCK_CLI_COMMAND_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cli/command-palette.hpp>

class MockCliCommand: public CliCommand {
public:
   MockCliCommand(): CliCommand() { };
   MOCK_METHOD((void), execute, (), ());
};

#endif // __MOCK_CLI_COMMAND_HPP__