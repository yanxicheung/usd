#include "Cent.h"
#include "BaseMacro.h"
#include <iostream>
#include <utility>
#include <list>
#include "Dollar.h"

using namespace std;
namespace
{
    string makeFormat(WORD32 amount)
    {
        return std::to_string(amount)+"￠";
    }

    using Item = pair<WORD16,WORD16>;

    list<Item> getItems(WORD32 restAmount)
    {
       const WORD16 centValue[] = {50,25,10,5,1};
       list<Item> items;
       for(int i = 0;i<sizeof(centValue)/sizeof(centValue[0]);++i)
       {
           WORD16 valueNum = restAmount/centValue[i];
           if(restAmount/centValue[i] == 0)
           {
               continue;
           }
           items.push_back(make_pair(valueNum,centValue[i]));
           restAmount %= centValue[i];
       }
       return items;
    }

    string combine(const list<Item> items)
    {
       string str;
       for(auto &item:items)
       {
           if(not str.empty())
           {
               str += ",";
           }
           str += std::to_string(item.first) + "*" + makeFormat(item.second);
       }
       return str;
    }
}

Cent::Cent(WORD32 amount):amount(amount)
{
}

WORD32 Cent::toBaseAmount() const
{
    return CENT_TO_BASE*amount;
}

std::string Cent::format1()
{
    return makeFormat(amount);
}

std::string Cent::format2()
{
    string result;
    string dolar = Dollar(amount/100).format2();
    string cent = combine(getItems(amount%100));

    if(not dolar.empty())
    {
        if(not cent.empty())
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
        if(not cent.empty())
        {
            result = cent;
        }
    }

    return result;
}
