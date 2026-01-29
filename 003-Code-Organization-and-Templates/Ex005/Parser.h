#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
class Parser
{
private:
    std::istream& input;
    std::string stopLine;

public:
    Parser(std::istream& input, const std::string& stopLine) : input(input), stopLine(stopLine)
    {
    }

    bool readNext(T& value)
    {
        std::string line;
        getline(input, line);

        if (line == stopLine)
        {
            return false;
        }

        std::istringstream isrt(line);
        isrt >> value;
        return true;
    }
};

#endif // PARSER_H
