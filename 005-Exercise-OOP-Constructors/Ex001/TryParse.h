#ifndef TRY_PARSE_H
#define TRY_PARSE_H

#include <sstream>


bool tryParse(const std::string &str, int &result) {
    std::istringstream istr(str);

    return static_cast<bool>(istr >> result);
}

#endif
