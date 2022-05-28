#ifndef __MOCK_CLI_INPUT_READER_HPP__
#define __MOCK_CLI_INPUT_READER_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cli/input-reader.hpp>

class MockInputReader: public InputReader {
public:
    MockInputReader(): InputReader(nullptr) { };
    MOCK_METHOD(std::string, readline, (), (override));
    MOCK_METHOD(void, readValue, (short int&), (override));
    ~MockInputReader() { }
};

#endif // __MOCK_CLI_INPUT_READER_HPP__
