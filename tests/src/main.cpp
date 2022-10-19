#include <iostream>
#include "gtest/gtest.h"
#include "log_print.h"
#include "platform_public_macro.h"
#include "c_log_print.h"

int main(int argc, char *argv[])
{
    INS(LogPrint).LogPrintInit(LogLevel::ERROR, LogPrintScreen::ENABLE, LogWriteFile::ENABLE);
    CLogPrintInit(DEBUG, PRINT_ENABLE, WRITE_ENABLE);
    C_LOG_ERROR(1, "print");
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
