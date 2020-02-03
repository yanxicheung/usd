#ifndef H18FDF3B0_4C53_4B34_A609_A638FF3D6D01
#define H18FDF3B0_4C53_4B34_A609_A638FF3D6D01

#include "base/BaseTypes.h"
#include <utility>
#include <list>
#include <string>

using std::string;
using std::pair;
using std::list;

using Item = pair<WORD16,WORD16>;
template<class T>
list<Item> getItems(WORD32 restAmount, T&value)
{
    list<Item> items;
    for (int i = 0; i < sizeof(value) / sizeof(value[0]); ++i)
    {
        WORD16 valueNum = restAmount / value[i];
        if (restAmount / value[i] == 0)
        {
            continue;
        }
        items.push_back(std::make_pair(valueNum, value[i]));
        restAmount %= value[i];
    }
    return items;
}

string combine(const list<Item> items, string (*format)(WORD32 amount));

#endif /* H18FDF3B0_4C53_4B34_A609_A638FF3D6D01 */
