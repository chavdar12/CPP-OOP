#ifndef TRY_PARSE_H
#define TRY_PARSE_H

#include <sstream>


const bool tryParse(const std::string& str, int& result)
{
    std::istringstream istr(str);

    istr >> result;

    return (bool)result;
}

#endif
