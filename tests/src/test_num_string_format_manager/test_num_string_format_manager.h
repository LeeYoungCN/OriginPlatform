#ifndef TEST_NUM_STRING_FORMAT_MANAGER_H
#define TEST_NUM_STRING_FORMAT_MANAGER_H
#include "gtest/gtest.h"
#include <iostream>
#include "num_string_format_manager.h"
#include "platform_public_macro.h"

struct TestCaseSt {
    std::string numStr;
    NumStrFmtEnum test_fmt;
    NumStrFmtEnum actual_fmt;
    std::string num_part;
    uint64_t num;
};

class TestNumStringFormatManager : public testing::Test {
protected:
    static void SetUpTestCase();
    static void TearDownTestCase();

    void SetUp();
    void TearDown();

    void TestIsRightFmt(TestCaseSt testCase);
};

#endif // TEST_NUM_STRING_FORMAT_MANAGER_H
