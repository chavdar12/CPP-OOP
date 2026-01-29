#ifndef MIN_AGR
#define MIN_AGR

#include "Aggregator.h"
#include <cmath>
#include <limits>

class MinAggregator : public StreamAggregator
{
public:
    MinAggregator(std::istream& stream) : StreamAggregator(stream)
    {
        this->aggregationResult = std::numeric_limits<int>::max();
    }

    void aggregate(int next) override
    {
        this->aggregationResult = std::min(aggregationResult, next);
        StreamAggregator::aggregate(next);
    }
};

#endif
