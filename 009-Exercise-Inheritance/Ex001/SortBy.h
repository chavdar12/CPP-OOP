#ifndef SORT_BY_H
#define SORT_BY_H

#include "Company.h"
#include <algorithm>>

template <typename T>
void sortBy(T* start, T* end, bool (*lessFunction)(const Company& a, const Company& b))
{
    std::sort(start, end, [lessFunction](const T& a, const T& b) { return lessFunction(*a, *b); });
}


#endif // !SORT_BY_H
