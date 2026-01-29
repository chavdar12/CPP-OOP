#include <iostream>
#include <vector>

int main()
{
    std::vector<std::pair<int, int>> ranges;

    while (true)
    {
        int from, to;
        std::cin >> from >> to;
        if (from == -1 && to == -1)
        {
            break;
        }
        ranges.push_back({from, to});
    }

    std::cin.ignore();

    while (true)
    {
        int num;
        std::cin >> num;
        if (num == -1)
        {
            break;
        }

        bool inRange = false;
        for (const auto& range : ranges)
        {
            if (num >= range.first && num <= range.second)
            {
                inRange = true;
                break;
            }
        }

        std::cout << (inRange ? "in" : "out") << std::endl;
    }

    return 0;
}
