#include <iostream>
#include <vector>
#include <algorithm>

#include "Company.h"

int main()
{
    std::vector<Company> companies;

    int id;
    std::string name;
    std::string line;
    while (std::getline(std::cin, line) && line != "end")
    {
        std::istringstream iss(line);
        iss >> name >> id;
        companies.emplace_back(id, name);
    }

    std::string sortCriteria;
    std::cin >> sortCriteria;

    if (sortCriteria == "name")
    {
        std::sort(companies.begin(), companies.end(), [](const Company& a, const Company& b)
        {
            return a.getName() < b.getName();
        });
    }
    else if (sortCriteria == "id")
    {
        std::sort(companies.begin(), companies.end(), [](const Company& a, const Company& b)
        {
            return a.getId() < b.getId();
        });
    }
    else
    {
        std::cerr << "Invalid sorting criteria" << std::endl;
        return 1;
    }

    for (Company& company : companies)
    {
        std::cout << company.toString() << std::endl;
    }

    return 0;
}
