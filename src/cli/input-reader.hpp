#ifndef __CLI_INPUT_READER_HPP__
#define __CLI_INPUT_READER_HPP__

#include <string>
#include <iostream>

class InputReader {
protected:
    std::istream* m_Input;
public:
    InputReader(std::istream* input);
    virtual std::string readline();
    virtual void readValue(short int& value);
    virtual void readValue(int32_t& value);
};

#endif // __CLI_INPUT_READER_HPP__