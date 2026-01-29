#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<map>

std::vector<std::pair<int, int>> readInputRanges()
{
    std::vector<std::pair<int, int>> vec;

    std::pair<int, int> currPair;
    const std::string delimiter = ".";
    std::string numbAsStr;
    while (true)
    {
        std::cin >> numbAsStr;
        if (numbAsStr == delimiter)
        {
            break;
        }
        currPair.first = std::stoi(numbAsStr);
        std::cin >> numbAsStr;
        currPair.second = std::stoi(numbAsStr);
        vec.push_back(currPair);
    }
    return vec;
}

std::map<int, int> getLowLimits(const std::vector<std::pair<int, int>>& inputRanges)
{
    std::map<int, int> lowLimits;
    const size_t vecSize = inputRanges.size();
    for (size_t i = 0; i < vecSize; i++)
    {
        const int currLowRange = inputRanges[i].first;
        lowLimits[currLowRange] = i;
    }

    return lowLimits;
}

std::map<int, int> getHighLimits(const std::vector<std::pair<int, int>>& inputRanges)
{
    std::map<int, int> highLimits;
    const size_t vecSize = inputRanges.size();
    for (size_t i = 0; i < vecSize; i++)
    {
        const int currHighRange = inputRanges[i].second;
        highLimits[currHighRange] = i;
    }

    return highLimits;
}

std::vector<int> readQueries()
{
    std::vector<int> queries{};

    //const std::string delimiter = ".";
    int query = 0;
    std::cin >> query;
    while (!std::cin.fail())
    {
        queries.push_back(query);
        std::cin >> query;
    }
    std::cin.clear();

    return queries;
}

void printSolution(const std::map<int, int>& lowLimits, const std::map<int, int>& highLimits,
                   const std::vector<int>& queries)
{
    const size_t queriesSize = queries.size();
    for (size_t i = 0; i < queriesSize; i++)
    {
        auto low = lowLimits.upper_bound(queries[i]);
        auto high = highLimits.lower_bound(queries[i]);
        if (high != highLimits.end())
        {
            bool isRange = low != lowLimits.begin() && ((--low)->second == high->second);
            if (isRange)
            {
                std::cout << "in" << std::endl;
            }
            else
            {
                std::cout << "out" << std::endl;
            }
        }
        else
        {
            std::cout << "out" << std::endl;
        }
    }
}
