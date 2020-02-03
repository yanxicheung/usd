#include "Cent.h"
#include "BaseMacro.h"
#include <iostream>
#include "Dollar.h"
#include "common.h"
using namespace std;
namespace
{
    string format(WORD32 amount)
    {
        return std::to_string(amount) + "￠";
    }

}

Cent::Cent(WORD32 amount)
: amount(amount)
{
}

WORD32 Cent::toBaseAmount() const
{
    return CENT_TO_BASE * amount;
}

std::string Cent::format1()
{
    return format(amount);
}

std::string Cent::format2()
{

    string dolar = Dollar(amount / 100).format2();

    const WORD16 centValue[] = { 50, 25, 10, 5, 1 };
    string cent = combine(getItems(amount % 100, centValue), format);

    string result;
    if (not dolar.empty())
    {
        if (not cent.empty())
        {
            result = dolar + "," + cent;
        }
        else
        {
            result = dolar;
        }
    }
    else
    {
        if (not cent.empty())
        {
            result = cent;
        }
    }

    return result;
}
