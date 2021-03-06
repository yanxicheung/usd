#ifndef H5038C978_D3BC_429B_BBDE_D9D2A1F1D96E
#define H5038C978_D3BC_429B_BBDE_D9D2A1F1D96E

#include "base/BaseTypes.h"
#include <string>
struct Cent
{
    Cent(WORD32 amount);
    WORD32 toBaseAmount() const;
    std::string format1();
    std::string format2();
private:
    WORD32 amount;
};

#define CENT(amount)  Cent(amount).toBaseAmount()

#endif /* H5038C978_D3BC_429B_BBDE_D9D2A1F1D96E */
