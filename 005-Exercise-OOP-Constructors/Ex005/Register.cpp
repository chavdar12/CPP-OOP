#include "Register.h"

Register::Register(size_t numCompanies) : numAdded(0)
{
    companiesArray = new Company[numCompanies];
}

void Register::add(const Company& c)
{
    companiesArray[this->numAdded] = c;
    this->numAdded++;
}

Company Register::get(int companyId) const
{
    for (unsigned i = 0; i < this->numAdded; i++)
    {
        if (companiesArray[i].getId() == companyId)
        {
            return companiesArray[i];
        }
    }
    return companiesArray[0];
}

Register::~Register()
{
    delete[] companiesArray;
}
