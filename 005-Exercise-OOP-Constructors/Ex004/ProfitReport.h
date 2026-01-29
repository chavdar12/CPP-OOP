#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H
#include "Company.h"
#include "ProfitCalculator.h"
// Place your code here, as well as any other #include directives you might need

#include <sstream>

std::string getProfitReport(Company* from, Company* to, std::map<int, ProfitCalculator>& calc)
{
    std::ostringstream ostr;

    while (true)
    {
        ProfitCalculator& pc = calc[from->getId()];

        ostr << from->getName() << " = " << pc.calculateProfit(*from) << std::endl;

        if (from == to) break;
        from++;
    }

    return ostr.str();
}


#endif // !PROFIT_REPORT_H
