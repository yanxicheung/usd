#include "gtest/gtest.h"
#include "Cent.h"
#include "Dollar.h"

struct FormatTest: testing::Test
{

};

TEST_F(FormatTest,test_dollar_format1)
{
    ASSERT_TRUE(Dollar(532).format1() == "$532");
    ASSERT_TRUE(Dollar(23).format1() == "$23");
}

TEST_F(FormatTest,test_cent_format1)
{
    ASSERT_TRUE(Cent(532).format1() == "532￠");
    ASSERT_TRUE(Cent(23).format1() == "23￠");
}

TEST_F(FormatTest,test_dollar_format2)
{
    ASSERT_TRUE(Dollar(532).format2() == "5*$100,1*$20,1*$10,1*$2");
    ASSERT_TRUE(Dollar(23).format2() == "1*$20,1*$2,1*$1");
    ASSERT_TRUE(Dollar(123).format2() == "1*$100,1*$20,1*$2,1*$1");
    ASSERT_TRUE(Dollar(0).format2() == "");
    ASSERT_TRUE(Dollar(103).format2() == "1*$100,1*$2,1*$1");
}

TEST_F(FormatTest,test_cent_format2)
{
    ASSERT_TRUE(Cent(1030).format2() == "1*$10,1*25￠,1*5￠");
    ASSERT_TRUE(Cent(10300).format2() == "1*$100,1*$2,1*$1");
    ASSERT_TRUE(Cent(56).format2() == "1*50￠,1*5￠,1*1￠");
    ASSERT_TRUE(Cent(91).format2() == "1*50￠,1*25￠,1*10￠,1*5￠,1*1￠");
}

