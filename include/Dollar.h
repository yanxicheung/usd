#ifndef HB583597E_7A43_4F9D_B469_4EA43F29779A
#define HB583597E_7A43_4F9D_B469_4EA43F29779A

#include "base/BaseTypes.h"

struct Dollar
{
    Dollar(WORD32 amount);
    bool operator==(const Dollar&rhs);
    bool operator!=(const Dollar&rhs);
    Dollar operator+(const Dollar&rhs);
    Dollar operator-(const Dollar&rhs);
private:
    WORD32 amount;
};

#endif /* HB583597E_7A43_4F9D_B469_4EA43F29779A */
