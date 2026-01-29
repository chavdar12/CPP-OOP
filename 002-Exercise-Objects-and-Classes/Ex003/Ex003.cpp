#include <iostream>
#include <iomanip>
#include <map>
#include <list>

struct sale
{
    std::string city;
    std::string product;
    double price;
    double quantity;

    explicit sale(std::istream& iss)
    {
        iss >> city >> product >> price >> quantity;
    }
};

int main()
{
    size_t sales_num;
    std::cin >> sales_num;

    std::list<sale> sales;
    while (sales_num--)
    {
        sales.emplace_back(std::cin);
    }

    std::map<std::string, double> sum;
    for (const sale& s : sales)
    {
        sum[s.city] += s.price * s.quantity;
    }

    for (const auto& curCity : sum)
    {
        std::cout << std::fixed << std::setprecision(2) << curCity.first << " -> " << curCity.second << '\n';
    }
}
