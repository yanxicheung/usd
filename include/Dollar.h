#ifndef HB583597E_7A43_4F9D_B469_4EA43F29779A
#define HB583597E_7A43_4F9D_B469_4EA43F29779A

#include "base/BaseTypes.h"

struct Dollar
{
    Dollar(WORD32 amount);
    WORD32 toBaseAmount() const;
private:
    WORD32 amount;
};

#define DOLLAR(amount)  Dollar(amount).toBaseAmount()

#endif /* HB583597E_7A43_4F9D_B469_4EA43F29779A */
