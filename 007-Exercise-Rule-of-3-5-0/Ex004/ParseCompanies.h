#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H
#include "Company.h"
// Place your code here 

#include <set>
#include <vector>
#include <string>
#include <sstream>

Company* parseUniqueCompanies(std::string companiesStr, int& numParsedComapnies,
                              std::string (&getUnique)(const Company&))
{
    std::istringstream companiesIn(companiesStr);

    numParsedComapnies = 0;

    std::set<std::string> parsedUnique;
    std::vector<Company> companies;

    std::string companyLine;
    while (std::getline(companiesIn, companyLine))
    {
        std::istringstream companyLineIn(companyLine);

        int id;
        std::string name;
        companyLineIn >> id >> name;

        Company company(id, name);
        std::string uniqueIdentifier = getUnique(company);

        if (parsedUnique.find(uniqueIdentifier) == parsedUnique.end())
        {
            companies.push_back(company);
            parsedUnique.insert(uniqueIdentifier);
        }
    }
    numParsedComapnies = companies.size();
    auto companiesPtr = new Company[companies.size()];

    for (unsigned i = 0; i < companies.size(); i++)
    {
        companiesPtr[i] = companies[i];
    }

    return companiesPtr;
}

#endif // !PARSE_COMPANIES_H
