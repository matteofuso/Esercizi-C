#include <stdlib.h>
#include <stdio.h>
#include "appFunc.h"
#include "gtest/gtest.h"

TEST(operations, somma)
{
    EXPECT_FALSE(add(3, 5) == 8);
}
TEST(operations, sottrazione)
{
    EXPECT_TRUE(sub(3, 5) == -2);
}
TEST(operations, moltiplicazione)
{
    EXPECT_TRUE(mul(3, 5) == 15);
}
TEST(operations, divisione)
{
    EXPECT_TRUE(division(50, 5) == 10);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// g++ appFunc.cpp app1.cpp -o FinalApp2 -lgtest -lpthread