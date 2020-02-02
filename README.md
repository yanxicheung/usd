# usd

美元(dollar)是美国作为存储债务的官方货币。用$表示，美分(cent)用￠表示。

目前流行的纸币面值包括：$1，$2，$5，$10，$20，$50，$100；

硬币面值包括：1￠，5￠，10￠，25￠，50￠，$1。

## sprint1

实现美元dollar的比较运算功能：

A. 1 dollar == 1 dollar

B. 1 dollar != 2 dollars

## sprint2

实现美元dollar的加减运算：

A. 1 dollar + 1 dollar == 2 dollars

B. 3 dollars - 1 dollar != 1 dollar

## sprint3

实现dollar和cent的混合运算：

A. 1 dollar == 100 cents

B. 1 dollar != 200 cents

C. 1 dollar + 100 cents == 2 dollars

D. 2 dollar - 100 cents != 2 dollars

## sprint4

按照指定格式进行打印：

格式1：按照货币原有单位进行打印：

A. 532 dollars => $532

B. 1030 cents => 10030￠

格式2：按照面值从大到小的顺序逐级打印：

A. $532 => 5*$100，1*$20，1*$10，1*$2

B. 1030￠=> 1*$10，1*25￠，1*5￠

注意： dollar的符号在前，而cent的符号在后。