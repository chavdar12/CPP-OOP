#ifndef ORDERED_INSERTER_H
#define ORDERED_INSERTER_H
#include "Company.h"
// Place your code here, as well as any other #include directives you might need 

#include <vector>

class OrderedInserter
{
private:
    std::vector<const Company*>& companies;

public:
    OrderedInserter(std::vector<const Company*>& companies_) : companies(companies_)
    {
    }

    void insert(const Company* c)
    {
        if (companies.size() == 0)
        {
            this->companies.push_back(c);
        }
        else
        {
            auto it = companies.begin();

            while (it != companies.end())
            {
                if ((*it)->getId() > c->getId())
                {
                    break;
                }
                it++;
            }

            companies.insert(it, c);
        }
    }
};


#endif // !ORDERED_INSERTER_H
