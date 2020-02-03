#include "gtest/gtest.h"
#include "Dollar.h"

TEST(DOLLARTest,test_equal_operator)
{
    ASSERT_TRUE(DOLLAR(1) == DOLLAR(1));
    ASSERT_TRUE(DOLLAR(8) == DOLLAR(8));
}

TEST(DOLLARTest,test_not_equal_operator)
{
    ASSERT_TRUE(DOLLAR(1) != DOLLAR(2));
    ASSERT_TRUE(DOLLAR(3) != DOLLAR(2));
}

TEST(DOLLARTest,test_add_operator)
{
    ASSERT_TRUE(DOLLAR(1) + DOLLAR(1) == DOLLAR(2));
    ASSERT_TRUE(DOLLAR(1) + DOLLAR(2) == DOLLAR(3));
}

TEST(DOLLARTest,test_sub_operator)
{
    ASSERT_TRUE(DOLLAR(3) - DOLLAR(1) == DOLLAR(2));
    ASSERT_TRUE(DOLLAR(3) - DOLLAR(1) != DOLLAR(1));
}
