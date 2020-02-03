#include "Dollar.h"
#include "BaseMacro.h"

Dollar::Dollar(WORD32 amount):amount(amount)
{
}

WORD32 Dollar::toBaseAmount() const
{
    return DOLLAR_TO_BASE*amount;
}
