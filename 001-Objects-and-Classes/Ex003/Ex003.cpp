#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct location
{
    std::string name;
    double latitude;
    double longitude;
};

bool is_equal(const double a, const double b)
{
    return std::abs(a - b) < 1e-6;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main()
{
    std::vector<location> locations;
    std::string input;
    while (std::getline(std::cin, input) && input != ".")
    {
        auto parts = split(input, ',');
        locations.push_back({parts[0], std::stod(parts[1]), std::stod(parts[2])});
    }

    while (std::getline(std::cin, input) && input != ".")
    {
        auto parts = split(input, ',');
        bool found = false;
        for (const location& loc : locations)
        {
            if ((parts.size() > 1 && is_equal(loc.latitude, std::stod(parts[0])) && is_equal(
                loc.longitude, std::stod(parts[1]))) || loc.name == input)
            {
                std::cout << loc.name << "," << loc.latitude << "," << loc.longitude << '\n';
                found = true;
                break;
            }
        }
        if (!found)
        {
            std::cout << "No matching location found." << '\n';
        }
    }

    return 0;
}
