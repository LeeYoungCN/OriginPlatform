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
    static std::string   Num2Str(UINT32 num, NumStrFmtEnum num_fmt);
    static UINT32        Str2Num(std::string num_str);
    static UINT32        Char2Num(CHAR c, NumStrFmtEnum num_fmt);
    // 字符串类型判断
    static bool          IsRightFmt(std::string num_str, NumStrFmtEnum num_fmt);
    static NumStrFmtEnum GetNumFmtType(std::string num_str);
    // 字符串分解
    bool                 HasPrefix(std::string num_str, NumStrFmtEnum num_fmt);
    static std::string   GetNumPart(std::string num_str);
    static UINT32        NumPartLen(std::string num_str, NumStrFmtEnum num_fmt);
};

#endif // NUM_STRING_FORMAT_MANAGER_H
