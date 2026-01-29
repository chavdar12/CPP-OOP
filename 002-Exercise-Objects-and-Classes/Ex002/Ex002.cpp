#include <iostream>
#include <cmath>
#include <iomanip>

struct point
{
    int x = 0;
    int y = 0;

    float get_dist(const int second_x, const int second_y) const
    {
        const int dx = second_x - x;
        const int dy = second_y - y;
        return std::sqrt(dx * dx + dy * dy);
    }
};

bool is_integral(const float number)
{
    return number - static_cast<int>(number) == 0;
}

int main()
{
    point first;
    std::cin >> first.x >> first.y;

    int x2, y2;
    std::cin >> x2 >> y2;

    const float dist = first.get_dist(x2, y2);
    std::cout << std::fixed << std::setprecision(is_integral(dist) ? 0 : 3) << dist;
}
