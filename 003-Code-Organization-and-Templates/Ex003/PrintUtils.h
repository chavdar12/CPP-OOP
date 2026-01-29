#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <vector>

template <class T>
void print_vector(const std::vector<T>& vec)
{
    for (const T& value : vec)
    {
        std::cout << value << ' ';
    }
    std::cout << std::endl;
}


#endif
