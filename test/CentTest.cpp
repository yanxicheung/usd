#include "gtest/gtest.h"
#include "Cent.h"
#include "Dollar.h"

TEST(DollarCentTest,dollar_and_cent_mixed_equal_test)
{
    ASSERT_TRUE(DOLLAR(1) == CENT(100));
    ASSERT_TRUE(CENT(100) == DOLLAR(1));
}

TEST(DollarCentTest,dollar_and_cent_mixed_not_equal_test)
{
    ASSERT_TRUE(DOLLAR(1) != CENT(200));
}

TEST(DollarCentTest,dollar_and_cent_mixed_add_test)
{
    ASSERT_TRUE(DOLLAR(1) + CENT(100) == DOLLAR(2));
    ASSERT_TRUE(CENT(100) + DOLLAR(1) == DOLLAR(2));
}

TEST(DollarCentTest,dollar_and_cent_mixed_sub_test)
{
    ASSERT_TRUE(DOLLAR(2) - CENT(100) == CENT(100));
    ASSERT_TRUE(DOLLAR(2) - CENT(100) == DOLLAR(1));
    ASSERT_TRUE(DOLLAR(2) - CENT(100) != DOLLAR(2));
}

