#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"
// Place your code here 

template <typename T>
void removeInvalid(T& companies)
{
    typename T::iterator itL = companies.begin();

    for (; itL != companies.end();)
    {
        Company* c = *itL;
        if (c->getId() < 0)
        {
            delete c;
            itL = companies.erase(itL);
        }
        else
        {
            itL++;
        }
    }
}


#endif // !REMOVE_INVALID_H
