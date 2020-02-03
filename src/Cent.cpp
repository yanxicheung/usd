#include "Cent.h"
#include "BaseMacro.h"

Cent::Cent(WORD32 amount):amount(amount)
{
}

WORD32 Cent::toBaseAmount() const
{
    return CENT_TO_BASE*amount;
}
