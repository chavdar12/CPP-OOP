#ifndef JOIN_H
#define JOIN_H

#include <sstream>
#include <string>
#include <vector>

template <typename T>
std::string join(const std::vector<T>& items, const std::string& joinStr)
{
    std::ostringstream oss;

    if (!items.empty())
    {
        oss << items[0];

        for (size_t i = 1; i < items.size(); ++i)
        {
            oss << joinStr << items[i];
        }
    }

    return oss.str();
}

#endif // JOIN_H
