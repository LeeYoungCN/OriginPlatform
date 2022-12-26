#include "num_string_format_manager.h"
#include <map>
#include <regex>
#include "log_print.h"

using namespace std;

namespace {
    struct NumFmtInfo {
        const uint32_t weight;
        const string prefix;
        const regex pattern;
    };

    using NumFmtInfoMap = map<NumStrFmtEnum, NumFmtInfo>;

    const NumFmtInfoMap g_numFmtInfoMap = {
        {NumStrFmtEnum::BIN, NumFmtInfo{2,  "0b", regex{"^0[bB][0-1]+$"}}},
        {NumStrFmtEnum::OCT, NumFmtInfo{8,  "0o", regex{"^0[oO][0-7]+$"}}},
        {NumStrFmtEnum::DEC, NumFmtInfo{10, "",   regex{"^[\\d]+$"}}},
        {NumStrFmtEnum::HEX, NumFmtInfo{16, "0x", regex{"^0[xX][\\da-fA-F]+$"}}},
    };

    const map<char, uint32_t> g_charToNum = {
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

    const char g_numToChar[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F'
    };
}

uint32_t NumStringFormatManager::moduleId = 0x01;
const char *NumStringFormatManager::moduleName = "NumStrFmtMgr";
// 数字与字符串装换
string NumStringFormatManager::Num2Str(const uint32_t num, const NumStrFmtEnum numFmt, const uint32_t digitNum)
{
    return "";
}

// 字符串转数字
uint32_t NumStringFormatManager::Str2Num(const string &numStr)
{
    NumStrFmtEnum numFmt = JudgeNumFmt(numStr);

    return (numFmt == NumStrFmtEnum::NONE ? 0 : Str2Num(numStr, numFmt));
}

// 字符串转数字
uint32_t NumStringFormatManager::Str2Num(const string &numStr, const NumStrFmtEnum numFmt)
{
    if (!IsRightFmt(numStr, numFmt)) {
        return 0;
    }

    const uint32_t weight = g_numFmtInfoMap.at(numFmt).weight;
    uint32_t tmpWeight = 1;
    uint32_t retNum = 0;
    uint32_t prefixLen = g_numFmtInfoMap.at(numFmt).prefix.length();

    for (uint32_t i = numStr.length(); i > prefixLen; i--) {
        retNum += Char2Num(numStr[i - 1], numFmt) * tmpWeight;
        tmpWeight *= weight;
    }
    LOG_EVENT(NumStringFormatManager::moduleId, "numStr=%s,num=%u", numStr.c_str(), retNum);
    return retNum;
}

// 字符转数字
uint32_t NumStringFormatManager::Char2Num(const char c, const NumStrFmtEnum numFmt)
{
    uint32_t num = g_charToNum.at(c);

    if (num >= g_numFmtInfoMap.at(numFmt).weight) {
        return 0;
    }

    return num;
}

// 字符串格式是否匹配
bool NumStringFormatManager::IsRightFmt(const string &numStr, const NumStrFmtEnum numFmt)
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
bool NumStringFormatManager::HasPrefix(const string &numStr, const NumStrFmtEnum numFmt)
{
    if (IsRightFmt(numStr, numFmt) == false) {
        return false;
    }

    string prefix = g_numFmtInfoMap.at(numFmt).prefix;
    uint32_t prefixLen = prefix.length();
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
uint32_t NumStringFormatManager::NumPartLen(const string &numStr, const NumStrFmtEnum numFmt)
{
    return GetNumPart(numStr, numFmt).length();
}
