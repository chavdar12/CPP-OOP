#ifndef SPLIT_H
#define SPLIT_H

#include <sstream>
#include <string>
#include <vector>

template <typename T>
std::vector<T> split(const std::string& line, char separator)
{
    std::vector<T> items;
    std::istringstream iss(line);
    std::string item;

    while (std::getline(iss, item, separator))
    {
        std::istringstream converter(item);
        T value;
        converter >> value;
        items.push_back(value);
    }

    return items;
}

#endif // SPLIT_H
