#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <iostream>

template <typename Template>
void printContainer(typename Template::iterator begin, typename Template::iterator end)
{
    while (begin != end)
    {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
}

#endif // PRINTUTILS_H
