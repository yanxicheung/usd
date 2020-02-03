#include "Cent.h"
#include "BaseMacro.h"

Cent::Cent(WORD32 amount):amount(amount)
{
}

WORD32 Cent::toBaseAmount() const
{
    return CENT_TO_BASE*amount;
}

std::string Cent::format1()
{
    return std::to_string(amount)+"￠";
}

std::string Cent::format2()
{
    return "1*$10,1*25￠,1*5￠";
}
