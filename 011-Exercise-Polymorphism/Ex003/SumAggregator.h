#ifndef SUM_AGR
#define SUM_AGR

#include "Aggregator.h"

class SumAggregator : public StreamAggregator
{
public:
    SumAggregator(std::istream& stream) : StreamAggregator(stream)
    {
        this->aggregationResult = 0;
    }

    void aggregate(int next) override
    {
        this->aggregationResult += next;
        StreamAggregator::aggregate(next);
    }
};

#endif
