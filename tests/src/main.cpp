#include <iostream>
#include "gtest/gtest.h"
#include "log_print.h"
#include "platform_public_macro.h"

int main(int argc, char *argv[])
{
    INS(LogPrint).LogPrintInit(LogLevel::ERROR, LogPrintScreen::ENABLE, LogWriteFile::ENABLE);
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
