#ifndef TEST_NUM_STRING_FORMAT_MANAGER_H
#define TEST_NUM_STRING_FORMAT_MANAGER_H
#include "gtest/gtest.h"
#include <iostream>
#include "num_string_format_manager.h"

struct TestCaseSt {
    std::string num_str;
    NumStrFmtEnum num_fmt;
};

class TestNumStringFormatManager : public testing::Test {
protected:
    static void SetUpTestCase();
    static void TearDownTestCase();

    void SetUp();
    void TearDown();

    void TestJudgeFmt(bool expectValue, TestCaseSt testCase);
};

#endif // TEST_NUM_STRING_FORMAT_MANAGER_H