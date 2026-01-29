#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

#include "Filter.h"
#include "DigitsFilter.h"
#include "CapitalsFilter.h"
#include "NonCapitalsFilter.h"

class FilterFactory
{
public:
    Filter* buildFilter(std::string filerDefinition) const
    {
        if (filerDefinition == "A-Z")
        {
            return new CapitalsFilter();
        }
        else if (filerDefinition == "a-z")
        {
            return new NonCapitalsFilter();
        }
        else if (filerDefinition == "0-9")
        {
            return new DigitsFilter();
        }
        else
        {
            return nullptr;
        }
    }
};


#endif
