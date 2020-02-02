#include "gtest/gtest.h"
#include "Dollar.h"

TEST(DollarTest,test_equal_operator)
{
    ASSERT_TRUE(Dollar(1) == Dollar(1));
    ASSERT_TRUE(Dollar(8) == Dollar(8));
}

TEST(DollarTest,test_not_equal_operator)
{
    ASSERT_TRUE(Dollar(1) != Dollar(2));
    ASSERT_TRUE(Dollar(3) != Dollar(2));
}


