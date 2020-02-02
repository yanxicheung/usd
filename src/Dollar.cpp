#include "Dollar.h"

Dollar::Dollar(WORD32 amount):amount(amount)
{
}

bool Dollar::operator ==(const Dollar& rhs)
{
    return this->amount == rhs.amount;
}

bool Dollar::operator !=(const Dollar& rhs)
{
    return not this->operator ==(rhs);
}

Dollar Dollar::operator +(const Dollar& rhs)
{
    return Dollar(this->amount + rhs.amount);
}

Dollar Dollar::operator -(const Dollar& rhs)
{
    return Dollar(this->amount - rhs.amount);
}
