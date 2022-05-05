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
        EXPECT_FALSE(CALL(IsRightFmt)(testCase.num_str, testCase.test_fmt)) << "IsRightFmt: " << testCase.num_str;
    } else {
        EXPECT_TRUE(CALL(IsRightFmt)(testCase.num_str, testCase.test_fmt)) << "IsRightFmt: " << testCase.num_str;
    }
    EXPECT_EQ(testCase.actual_fmt,  CALL(JudgeNumFmt)(testCase.num_str)) << "GetNumFmtType: " << testCase.num_str;
    EXPECT_EQ(testCase.num_part,    CALL(GetNumPart)(testCase.num_str, testCase.test_fmt)) << "GetNumPart";
    EXPECT_EQ(testCase.num, CALL(Str2Num(testCase.num_str))) << "Str2Num: " << testCase.num_str;
}

TEST_F(TestNumStringFormatManager, IsRightFmt_true)
{
    std::vector<TestCaseSt> testCaseVec = {
        {"0x0123456789",    ENUM(HEX), ENUM(HEX), "0123456789",     4886718345},
        {"0xabcdefABCDEF",  ENUM(HEX), ENUM(HEX), "abcdefABCDEF",   188900977659375},
        {"0x123aBcDeF",     ENUM(HEX), ENUM(HEX), "123aBcDeF",      4893429231},
        {"0o01234567",      ENUM(OCT), ENUM(OCT), "01234567",       342391},
        {"0123456789",      ENUM(DEC), ENUM(DEC), "0123456789",     123456789},
        {"1234000234",      ENUM(DEC), ENUM(DEC), "1234000234",     1234000234},
        {"0b01",            ENUM(BIN), ENUM(BIN), "01",             1},
        {"0b0111",          ENUM(BIN), ENUM(BIN), "0111",           7},
        // 超范围
        {"0xghijkGHIJK",    ENUM(HEX), ENUM(NONE), "",              0},
        {"abcdefghiasd",    ENUM(HEX), ENUM(NONE), "",              0},
        {"0o89",            ENUM(OCT), ENUM(NONE), "",              0},
        {"0b23456789a",     ENUM(BIN), ENUM(NONE), "",              0},
        // 无内容
        {"0x",              ENUM(HEX), ENUM(NONE), "",              0},
        {"0o",              ENUM(OCT), ENUM(NONE), "",              0},
        {"",                ENUM(DEC), ENUM(NONE), "",              0},
        {"0b",              ENUM(BIN), ENUM(NONE), "",              0},
    };

    for (const auto& testCase : testCaseVec) {
        TestIsRightFmt(testCase);
    }
}
