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
    if (testCase.num_fmt == ENUM(NONE)) {
        EXPECT_FALSE(CALL(IsRightFmt)(testCase.num_str, testCase.num_fmt)) << "IsRightFmt";
    } else {
        EXPECT_TRUE(CALL(IsRightFmt)(testCase.num_str, testCase.num_fmt)) << "IsRightFmt";
    }
    EXPECT_EQ(testCase.num_fmt,  CALL(JudgeNumFmt)(testCase.num_str)) << "GetNumFmtType";
    EXPECT_EQ(testCase.num_part, CALL(GetNumPart)(testCase.num_str)) << "GetNumPart";
}

TEST_F(TestNumStringFormatManager, IsRightFmt_true)
{
    std::vector<TestCaseSt> testCaseVec = {
        {"0x0123456789",    ENUM(HEX),  "0123456789"},
        {"0xabcdefABCDEF",  ENUM(HEX),  "abcdefABCDEF"},
        {"0o01234567",      ENUM(OCT),  "01234567"},
        {"0123456789",      ENUM(DEC),  "0123456789"},
        {"0b01",            ENUM(BIN),   "01"},
        // 超范围
        {"0xghijkGHIJK",    ENUM(NONE), ""},
        {"abcdefghiasd",    ENUM(NONE), ""},
        {"0o89",            ENUM(NONE), ""},
        {"0b23456789a",     ENUM(NONE), ""},
        // 无内容
        {"0x",              ENUM(NONE), ""},
        {"0o",              ENUM(NONE), ""},
        {"",                ENUM(NONE), ""},
        {"0b",              ENUM(NONE), ""},
    };

    for (const auto& testCase : testCaseVec) {
        TestIsRightFmt(testCase);
    }
}
