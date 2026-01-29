#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <sstream>

template <typename T>
class Parser
{
private:
    std::istream& input;
    std::string stop_line_;

public:
    Parser(std::istream& input, std::string stop_line) : input(input), stop_line_(std::move(stop_line))
    {
    }

    bool readNext(T& value)
    {
        std::string line;
        getline(input, line);

        if (line == stop_line_)
        {
            return false;
        }

        std::istringstream isrt(line);
        isrt >> value;
        return true;
    }
};


#endif
