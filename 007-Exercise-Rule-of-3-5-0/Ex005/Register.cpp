#include "Register.h"

#include <cstdlib>
#include <iostream>

Register::Register(size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies])
{
}

void Register::add(const Company& c)
{
    this->companiesArray[this->numAdded++] = c;
}

Company Register::get(int companyId) const
{
    for (unsigned i = 0; i < this->numAdded; i++)
    {
        if (this->companiesArray[i].getId() == companyId) return this->companiesArray[i];
    }
    return Company();
}

Register::~Register()
{
    delete[] this->companiesArray;
}

Register& Register::operator=(const Register& other)
{
    if (this != &other)
    {
        auto temp = new Company[other.numAdded];
        for (unsigned i = 0; i < other.numAdded; i++)
        {
            temp[i] = other.companiesArray[i];
        }

        if (this != nullptr)
        {
            delete[] this->companiesArray;
        }

        this->numAdded = other.numAdded;
        this->companiesArray = temp;
    }
    return *this;
}

Register::Register(const Register& other)
{
    this->numAdded = other.numAdded;
    this->companiesArray = new Company[other.numAdded];
    for (unsigned i = 0; i < other.numAdded; i++)
    {
        this->companiesArray[i] = other.companiesArray[i];
    }
}
