#include "test_num_string_format_manager.h"

#define CALL(func) NumStringFormatManager::func

void TestNumStringFormatManager::SetUpTestCase() {}
void TestNumStringFormatManager::TearDownTestCase() {}

void TestNumStringFormatManager::SetUp() {}
void TestNumStringFormatManager::TearDown() {}

void TestNumStringFormatManager::TestJudgeFmt(bool expectValue, TestCaseSt testCase)
{
    EXPECT_EQ(
        expectValue,
        CALL(IsRightFmt)(testCase.num_str, testCase.num_fmt)
    ) << testCase.num_str;
}

TEST_F(TestNumStringFormatManager, JudgeFmt)
{
    TestJudgeFmt(true, TestCaseSt{"0x1", NumStrFmtEnum::HEX});
    TestJudgeFmt(true, TestCaseSt{"1", NumStrFmtEnum::HEX});
    TestJudgeFmt(false, TestCaseSt{"0Wb1", NumStrFmtEnum::HEX});
}
