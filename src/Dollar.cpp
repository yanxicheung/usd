#include "Dollar.h"
#include "BaseMacro.h"
#include <iostream>
#include "common.h"

using namespace std;
namespace
{
    string format(WORD32 amount)
    {
        return "$" + std::to_string(amount);
    }

}

Dollar::Dollar(WORD32 amount)
: amount(amount)
{
}

WORD32 Dollar::toBaseAmount() const
{
    return DOLLAR_TO_BASE * amount;
}

std::string Dollar::format1()
{
    return format(amount);
}

std::string Dollar::format2()
{
    const WORD16 dolarValue[] = { 100, 50, 20, 10, 5, 2, 1 };
    return combine(getItems(amount, dolarValue), format);
}
