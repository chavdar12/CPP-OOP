#ifndef ARRAY_H
#define ARRAY_H

#include "Company.h"
#include <vector>
#include <memory>

class ArrayOfPointers
{
private:
    std::vector<std::shared_ptr<Company>> pointers;

public:
    ArrayOfPointers()
    {
    }

    void add(Company* c)
    {
        this->pointers.push_back(std::shared_ptr<Company>(c));
    }

    int getSize() const
    {
        return this->pointers.size();
    }

    Company* get(int index) const
    {
        return this->pointers.at(index).get();
    }
};

#endif
