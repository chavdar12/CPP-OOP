#include "BigInt.h"
#include <iostream>
using namespace std;

unsigned sumOfDigits(const string& numDigits)
{
    unsigned result = 0;
    for (unsigned i = 0; i < numDigits.length(); i++)
    {
        result += (numDigits[i] - '0');
    }
    return result;
}

bool isDivBy45(const BigInt& number)
{
    string numStr = number.getDigits();

    if (numStr[numStr.length() - 1] == '5' || numStr[numStr.length() - 1] == '0')
    {
        if (sumOfDigits(numStr) % 9 == 0)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string start, finish;

    cin >> start >> finish;

    BigInt from(start), to(finish);

    for (BigInt i = from; i < to; i += BigInt(1))
    {
        if (isDivBy45(i)) std::cout << i << std::endl;
    }

    return 0;
}
