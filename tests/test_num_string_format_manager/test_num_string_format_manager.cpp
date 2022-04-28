#include "test_num_string_format_manager.h"
#include <vector>

#define CALL(func) NumStringFormatManager::func
#define ENUM(type) NumStrFmtEnum::type

void TestNumStringFormatManager::SetUpTestCase() {}
void TestNumStringFormatManager::TearDownTestCase() {}

void TestNumStringFormatManager::SetUp() {}
void TestNumStringFormatManager::TearDown() {}

void TestNumStringFormatManager::TestIsRightFmt(TestCaseSt testCase)
{
    if (testCase.actual_fmt == ENUM(NONE)) {
        EXPECT_FALSE(CALL(IsRightFmt)(testCase.num_str, testCase.test_fmt)) << "IsRightFmt";
    } else {
        EXPECT_TRUE(CALL(IsRightFmt)(testCase.num_str, testCase.test_fmt)) << "IsRightFmt";
    }
    EXPECT_EQ(testCase.actual_fmt,  CALL(JudgeNumFmt)(testCase.num_str)) << "GetNumFmtType";
    EXPECT_EQ(testCase.actual_fmt,  CALL(JudgeNumFmt)(testCase.num_str, testCase.test_fmt)) << "GetNumFmtType";
    EXPECT_EQ(testCase.num_part,    CALL(GetNumPart)(testCase.num_str, testCase.test_fmt)) << "GetNumPart";
}

TEST_F(TestNumStringFormatManager, IsRightFmt_true)
{
    std::vector<TestCaseSt> testCaseVec = {
        {"0x0123456789",    ENUM(HEX), ENUM(HEX), "0123456789"},
        {"0xabcdefABCDEF",  ENUM(HEX), ENUM(HEX), "abcdefABCDEF"},
        {"0o01234567",      ENUM(OCT), ENUM(OCT), "01234567"},
        {"0123456789",      ENUM(DEC), ENUM(DEC), "0123456789"},
        {"0b01",            ENUM(BIN), ENUM(BIN), "01"},
        // 超范围
        {"0xghijkGHIJK",    ENUM(HEX), ENUM(NONE), ""},
        {"abcdefghiasd",    ENUM(HEX), ENUM(NONE), ""},
        {"0o89",            ENUM(OCT), ENUM(NONE), ""},
        {"0b23456789a",     ENUM(BIN), ENUM(NONE), ""},
        // 无内容
        {"0x",              ENUM(HEX), ENUM(NONE), ""},
        {"0o",              ENUM(OCT), ENUM(NONE), ""},
        {"",                ENUM(DEC), ENUM(NONE), ""},
        {"0b",              ENUM(BIN), ENUM(NONE), ""},
    };

    for (const auto& testCase : testCaseVec) {
        TestIsRightFmt(testCase);
    }
}
