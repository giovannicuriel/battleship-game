#include <iostream>
#include <cli/input-reader.hpp>

InputReader::InputReader(std::istream* input): m_Input(input) { } 

std::string InputReader::readline() {
    std::string text;
    getline(*m_Input, text);
    return text;
}

void InputReader::readValue(short int& value) { 
    (*m_Input) >> value;
}