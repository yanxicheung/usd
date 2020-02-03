#include "Dollar.h"
#include "BaseMacro.h"
#include <iostream>
#include <utility>
#include <list>

using namespace std;
namespace
{
    string makeFormat(WORD32 amount)
    {
        return "$"+std::to_string(amount);
    }

    using Item = pair<WORD16,WORD16>;

    list<Item> getItems(WORD32 restAmount)
    {
        const WORD16 dolarValue[] = {100,50,20,10,5,2,1};
        list<Item> items;
        for(int i = 0;i<sizeof(dolarValue)/sizeof(dolarValue[0]);++i)
        {
            WORD16 valueNum = restAmount/dolarValue[i];
            if(restAmount/dolarValue[i] == 0)
            {
                continue;
            }
            items.push_back(make_pair(valueNum,dolarValue[i]));
            restAmount %= dolarValue[i];
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

Dollar::Dollar(WORD32 amount):amount(amount)
{
}

WORD32 Dollar::toBaseAmount() const
{
    return DOLLAR_TO_BASE*amount;
}

std::string Dollar::format1()
{
    return makeFormat(amount);
}

/*
 *
 *目前流行的纸币面值包括：$1，$2，$5，$10，$20，$50，$100；
  硬币面值包括：1￠，5￠，10￠，25￠，50￠，$1。
 *
 * */
std::string Dollar::format2()
{
    return combine(getItems(amount));
}
