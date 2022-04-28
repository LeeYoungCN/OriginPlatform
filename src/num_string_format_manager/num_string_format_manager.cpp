#include "num_string_format_manager.h"
#include <map>
#include <regex>

using namespace std;

namespace {
    struct NumFmtInfo {
        UINT32 weight;
        string prefix;
        regex pattern;
    };

    using NumFmtInfoMap = map<NumStrFmtEnum, NumFmtInfo>;

    const NumFmtInfoMap NUM_FMT_INFO_MAP = {
        {NumStrFmtEnum::BIN, NumFmtInfo{2,  "0b", regex{"^0b[0-1]+$"}}},
        {NumStrFmtEnum::OCT, NumFmtInfo{8,  "0o", regex{"^0o[0-7]+$"}}},
        {NumStrFmtEnum::DEC, NumFmtInfo{10, "",   regex{"^[0-9]+$"}}},
        {NumStrFmtEnum::HEX, NumFmtInfo{16, "0x", regex{"^0x[0-9a-fA-F]+$"}}},
    };

    const map<CHAR, UINT32> HEX_CHAR_TO_NUM = {
        {'A', 10}, {'a', 10},
        {'B', 11}, {'b', 11},
        {'C', 12}, {'c', 12},
        {'D', 13}, {'d', 13},
        {'E', 14}, {'e', 14},
        {'F', 15}, {'f', 15},
    };
}

// 数字与字符串装换
string NumStringFormatManager::Num2Str(UINT32 num, NumStrFmtEnum num_fmt)
{
    return "";
}

UINT32 NumStringFormatManager::Str2Num(string num_str)
{
    NumStrFmtEnum num_fmt = GetNumFmtType(num_str);

    if (num_fmt == NumStrFmtEnum::NONE) {
        return 0;
    }

    UINT32 wieght = 1;
    UINT32 ret_num = 0;
    UINT32 prefixLen = NUM_FMT_INFO_MAP.at(num_fmt).prefix.length();

    for (UINT32 i = num_str.length(); i > prefixLen; i--) {
        ret_num += Char2Num(num_str[i - 1], num_fmt) * wieght;
        wieght *= NUM_FMT_INFO_MAP.at(num_fmt).weight;
    }
    return ret_num;
}

UINT32 NumStringFormatManager::Char2Num(CHAR c, NumStrFmtEnum num_fmt)
{
    UINT32 num = 0;
    if (c >= '0' && c <= '9') {
        num = c - '0';
    } else if (num_fmt == NumStrFmtEnum::HEX) {
        num = HEX_CHAR_TO_NUM.at(c);
    }

    if (num >= NUM_FMT_INFO_MAP.at(num_fmt).weight) {
        return 0;
    }

    return num;
}

// 字符串格式判断
bool NumStringFormatManager::IsRightFmt(string num_str, NumStrFmtEnum num_fmt)
{
    return regex_match(num_str, NUM_FMT_INFO_MAP.at(num_fmt).pattern);
}

NumStrFmtEnum NumStringFormatManager::GetNumFmtType(string num_str)
{
    for (const auto& [fmt, _] : NUM_FMT_INFO_MAP) {
        if (IsRightFmt(num_str, fmt)) {
            return fmt;
        }
    }
    return NumStrFmtEnum::NONE;
}

// 字符串分解
bool NumStringFormatManager::HasPrefix(string num_str, NumStrFmtEnum num_fmt)
{
    if (!IsRightFmt(num_str, num_fmt)) {
        return false;
    }
    string prefix = NUM_FMT_INFO_MAP.at(num_fmt).prefix;
    UINT32 prefixLen = prefix.length();
    if (num_str.length() < prefixLen) {
        return true;
    }

    if (prefix.compare(0, prefixLen, num_str, 0, prefixLen) == 0) {
        return true;
    }

    return false;
}

string NumStringFormatManager::GetNumPart(string num_str)
{
    NumStrFmtEnum num_fmt = GetNumFmtType(num_str);

    if (num_fmt == NumStrFmtEnum::NONE) {
        return "";
    }
    
    try {
        return num_str.substr(NUM_FMT_INFO_MAP.at(num_fmt).prefix.length());
    } catch(std::exception& e) {
        cout << num_str << endl;
        cout << (int)(num_fmt) << endl;
        return "";
    }
}

UINT32 NumStringFormatManager::NumPartLen(string num_str, NumStrFmtEnum num_fmt)
{
    return GetNumPart(num_str).length();
}
