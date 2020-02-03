#include "common.h"
string combine(const list<Item> items, string (*format)(WORD32 amount))
{
    string str;
    for (auto &item : items)
    {
        if (not str.empty())
        {
            str += ",";
        }
        str += std::to_string(item.first) + "*" + format(item.second);
    }
    return str;
}

