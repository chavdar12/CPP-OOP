#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H
#include "Company.h"
// Place your code here 

#include <memory>
#include <vector>
#include <cstdlib>

const int toInt(const std::string& a)
{
    int i;
    std::istringstream(a) >> i;
    return i;
}

std::shared_ptr<Company> makeCompany(std::vector<std::string> properties)
{
    int id = toInt(properties[0]);
    std::string name = properties[1];

    std::vector<std::pair<char, char>> emplInitials;
    for (unsigned i = 2; i < properties.size(); i++)
    {
        std::string initialsPair = properties[i];
        emplInitials.push_back(std::pair<char, char>(initialsPair[0], initialsPair[1]));
    }
    return std::shared_ptr<Company>(new Company(id, name, emplInitials));
}

#endif // !MAKE_COMPANY_H
