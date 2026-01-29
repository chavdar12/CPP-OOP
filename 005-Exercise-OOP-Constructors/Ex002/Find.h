#ifndef FIND_H
#define FIND_H
#include "Company.h"

// Place your code here, as well as any other #include directives you might need

#include <algorithm>
#include <vector>

static int searchId;

const bool findId(Company* c)
{
    return c->getId() == searchId;
}

Company* find(std::vector<Company*>& companies, const int sId)
{
    searchId = sId;
    auto it = find_if(companies.begin(), companies.end(), findId);
    //auto it = find_if(companies.begin(), companies.end(), [&](Company *c){ return c->getId() == sId; }};

    return it == companies.end() ? nullptr : *it;
}


#endif // !FIND_H
