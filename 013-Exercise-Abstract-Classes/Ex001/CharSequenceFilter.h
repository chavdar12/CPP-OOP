#ifndef CHAR_SEQ_FILTER_H
#define CHAR_SEQ_FILTER_H

#include "Filter.h"

class CharSequenceFilter : public Filter
{
private:
    char fromChar;
    char toChar;

public:
    CharSequenceFilter(char from, char to) : fromChar(from), toChar(to)
    {
    }

    bool shouldFilterOut(char symbol) const override
    {
        return this->fromChar <= symbol && symbol <= this->toChar;
    }
};

#endif
