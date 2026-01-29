#include "IndexedSet.h"

void IndexedSet::buildIndex()
{
    const size_t size = this->valuesSet.size();
    this->valuesArray = new Value[size];

    size_t idx = 0;
    for (const Value& value : valuesSet)
    {
        valuesArray[idx] = value;
        ++idx;
    }
}

void IndexedSet::clearIndex()
{
    if (valuesArray)
    {
        delete[] valuesArray;
        valuesArray = nullptr;
    }
}

IndexedSet::IndexedSet() : valuesArray(nullptr)
{
}

IndexedSet::~IndexedSet()
{
    clearIndex();
}

IndexedSet::IndexedSet(const IndexedSet& other) : valuesSet(other.valuesSet), valuesArray(nullptr)
{
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other)
{
    if (this != &other)
    {
        valuesSet = other.valuesSet;
        clearIndex();
    }
    return *this;
}

size_t IndexedSet::size() const
{
    return valuesSet.size();
}

void IndexedSet::add(const Value& v)
{
    valuesSet.insert(v);
    clearIndex();
}

const Value& IndexedSet::operator[](size_t index)
{
    if (valuesArray == nullptr)
    {
        buildIndex();
    }
    return valuesArray[index];
}
