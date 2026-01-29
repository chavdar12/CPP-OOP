#ifndef AVG_AGR
#define AVG_AGR

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator
{
private:
    int curSum = 0;

public:
    AverageAggregator(std::istream& stream) : StreamAggregator(stream)
    {
        this->aggregationResult = 0;
    }

    void aggregate(int next) override
    {
        this->curSum += next;
        StreamAggregator::aggregate(next);
        this->aggregationResult = curSum / getNumAggregated();
    }
};

#endif
