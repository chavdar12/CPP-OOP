#include <iostream>
#include <string>
#include <sstream>
#include <set>

#include "Article13Filter.h"

int main()
{
    std::string copyrighted_line;
    std::getline(std::cin, copyrighted_line);

    std::set<std::string> copyrighted;
    std::istringstream line_in(copyrighted_line);
    std::string copyrighted_item;
    while (line_in >> copyrighted_item)
    {
        copyrighted.insert(copyrighted_item);
    }

    Article13Filter filter(copyrighted);

    std::string input_line;
    while (std::getline(std::cin, input_line) && input_line != "end")
    {
        if (!filter.block_if_copyrighted(input_line))
        {
            std::cout << input_line << '\n';
        }
    }

    std::cout << "Blocked: ";
    for (const std::string& blocked_item : filter.get_blocked())
    {
        std::cout << blocked_item << " ";
    }

    return 0;
}
