#ifndef NON_CAPTITALS_FILTER_H
#define NON_CAPTITALS_FILTER_H

#include "CharSequenceFilter.h"

class NonCapitalsFilter : public CharSequenceFilter
{
public:
    NonCapitalsFilter() : CharSequenceFilter('a', 'z')
    {
    };
};


#endif
