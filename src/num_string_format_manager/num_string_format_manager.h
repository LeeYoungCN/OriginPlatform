#ifndef NUM_STRING_FORMAT_MANAGER_H
#define NUM_STRING_FORMAT_MANAGER_H
#include <iostream>
#include "public_typedef.h"

enum class NumStrFmtEnum {
    NONE = 0,
    BIN = 2,
    OCT = 8,
    DEC = 10,
    HEX = 16,
};

class NumStringFormatManager {
public:
    // 数字与字符串转换
    static std::string   Num2Str(const UINT32 num, const NumStrFmtEnum &num_fmt);
    static UINT32        Str2Num(const std::string &num_str, const NumStrFmtEnum &num_fmt = NumStrFmtEnum::NONE);
    static UINT32        Char2Num(const CHAR c, const NumStrFmtEnum &num_fmt);
    // 字符串类型判断
    static NumStrFmtEnum JudgeNumFmt(const std::string &num_str, const NumStrFmtEnum &num_fmt = NumStrFmtEnum::NONE);
    static bool          IsRightFmt(const std::string &num_str, const NumStrFmtEnum &num_fmt);
    // 字符串分解
    static bool          HasPrefix(const std::string &num_str, const NumStrFmtEnum &num_fmt);
    static std::string   GetNumPart(const std::string &num_str, const NumStrFmtEnum &num_fmt);
    static UINT32        NumPartLen(const std::string &num_str, const NumStrFmtEnum &num_fmt);
};

#endif // NUM_STRING_FORMAT_MANAGER_H
