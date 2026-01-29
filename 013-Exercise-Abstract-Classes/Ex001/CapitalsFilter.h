#ifndef CAPTITALS_FILTER_H
#define CAPTITALS_FILTER_H

#include "CharSequenceFilter.h"

class CapitalsFilter : public CharSequenceFilter
{
public:
    CapitalsFilter() : CharSequenceFilter('A', 'Z')
    {
    };
};


#endif
