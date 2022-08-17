#include <iostream>
#include "gtest/gtest.h"

typedef char INT8;
typedef unsigned char UINT8;

int main(int argc, char *argv[])
{
    INT8 a = -5;
    int b = -10;

    printf("a=%d\n", b + a);
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
