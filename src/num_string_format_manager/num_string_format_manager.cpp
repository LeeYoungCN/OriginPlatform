#include "num_string_format_manager.h"
#include <map>
#include <regex>
#include "log_print.h"

using namespace std;

namespace {
    struct NumFmtInfo {
        const UINT32 weight;
        const string prefix;
        const regex pattern;
    };

    using NumFmtInfoMap = map<NumStrFmtEnum, NumFmtInfo>;

    const NumFmtInfoMap g_numFmtInfoMap = {
        {NumStrFmtEnum::BIN, NumFmtInfo{2,  "0b", regex{"^0b[0-1]+$"}}},
        {NumStrFmtEnum::OCT, NumFmtInfo{8,  "0o", regex{"^0o[0-7]+$"}}},
        {NumStrFmtEnum::DEC, NumFmtInfo{10, "",   regex{"^[\\d]+$"}}},
        {NumStrFmtEnum::HEX, NumFmtInfo{16, "0x", regex{"^0x[\\da-fA-F]+$"}}},
    };

    const map<CHAR, UINT32> g_charToNum = {
        {'0',  0},  {'1',  1},
        {'2',  2},  {'3',  3},
        {'4',  4},  {'5',  5},
        {'6',  6},  {'7',  7},
        {'8',  8},  {'9',  9},
        // 十六进制字符
        {'A', 10},  {'a', 10},
        {'B', 11},  {'b', 11},
        {'C', 12},  {'c', 12},
        {'D', 13},  {'d', 13},
        {'E', 14},  {'e', 14},
        {'F', 15},  {'f', 15},
    };

    const CHAR g_numToChar[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F'
    };
}

UINT32 NumStringFormatManager::moduleId = 0x01;
const CHAR *NumStringFormatManager::moduleName = "NumStrFmtMgr";
// 数字与字符串装换
string NumStringFormatManager::Num2Str(const UINT32 num, const NumStrFmtEnum numFmt)
{
    return "";
}

// 字符串转数字
UINT32 NumStringFormatManager::Str2Num(const string &numStr)
{
    NumStrFmtEnum numFmt = JudgeNumFmt(numStr);

    return (numFmt == NumStrFmtEnum::NONE ? 0 : Str2Num(numStr, numFmt));
}

// 字符串转数字
UINT32 NumStringFormatManager::Str2Num(const string &numStr, const NumStrFmtEnum numFmt)
{
    if (!IsRightFmt(numStr, numFmt)) {
        return 0;
    }

    const UINT32 weight = g_numFmtInfoMap.at(numFmt).weight;
    UINT32 tmpWeight = 1;
    UINT32 retNum = 0;
    UINT32 prefixLen = g_numFmtInfoMap.at(numFmt).prefix.length();

    for (UINT32 i = numStr.length(); i > prefixLen; i--) {
        retNum += Char2Num(numStr[i - 1], numFmt) * tmpWeight;
        tmpWeight *= weight;
    }
    LOG_EVENT(NumStringFormatManager::moduleId, "numStr=%s,num=%u", numStr.c_str(), retNum);
    return retNum;
}

// 字符转数字
UINT32 NumStringFormatManager::Char2Num(const CHAR c, const NumStrFmtEnum numFmt)
{
    UINT32 num = g_charToNum.at(c);

    if (num >= g_numFmtInfoMap.at(numFmt).weight) {
        return 0;
    }

    return num;
}

// 字符串格式是否匹配
BOOL NumStringFormatManager::IsRightFmt(const string &numStr, const NumStrFmtEnum numFmt)
{
    if (numFmt == NumStrFmtEnum::NONE) {
        return false;
    }

    return regex_match(numStr, g_numFmtInfoMap.at(numFmt).pattern);
}

// 判断字符串格式
NumStrFmtEnum NumStringFormatManager::JudgeNumFmt(const string &numStr)
{
    for (const auto& [fmt, _] : g_numFmtInfoMap) {
        if (IsRightFmt(numStr, fmt)) {
            return fmt;
        }
    }
    return NumStrFmtEnum::NONE;
}

// 字符串分解
BOOL NumStringFormatManager::HasPrefix(const string &numStr, const NumStrFmtEnum numFmt)
{
    if (IsRightFmt(numStr, numFmt) == false) {
        return false;
    }

    string prefix = g_numFmtInfoMap.at(numFmt).prefix;
    UINT32 prefixLen = prefix.length();
    if (numStr.length() < prefixLen) {
        return true;
    }

    if (prefix.compare(0, prefixLen, numStr, 0, prefixLen) == 0) {
        return true;
    }

    return false;
}

// 获取字符串数字部分
string NumStringFormatManager::GetNumPart(const string &numStr, const NumStrFmtEnum numFmt)
{
    if (!IsRightFmt(numStr, numFmt)) {
        return "";
    }
    
    return numStr.substr(g_numFmtInfoMap.at(numFmt).prefix.length());
}

// 字符串数字部分的长度
UINT32 NumStringFormatManager::NumPartLen(const string &numStr, const NumStrFmtEnum numFmt)
{
    return GetNumPart(numStr, numFmt).length();
}
