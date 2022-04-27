#ifndef NUM_STRING_FORMAT_MANAGER_H
#define NUM_STRING_FORMAT_MANAGER_H
#include <iostream>
#include "public_typedef.h"

enum class NumStrFmtEnum {
    BIN = 2,
    OCT = 8,
    DEC = 10,
    HEX = 16,
};

class NumStringFormatManager {
public:
    static std::string Num2Str(UINT32 num, NumStrFmtEnum num_fmt);
    static UINT32      Str2Num(std::string num_str, NumStrFmtEnum num_fmt);
    static bool        IsRightFmt(std::string num_str, NumStrFmtEnum num_fmt);
    static bool        HasPrefix(std::string num_str, NumStrFmtEnum num_fmt);
    static std::string GetNumPart(std::string num_str, NumStrFmtEnum num_fmt);
    static UINT32      NumPartLen(std::string num_str, NumStrFmtEnum num_fmt);
    static UINT32      Char2Num(CHAR c, NumStrFmtEnum num_fmt);
};

#endif // NUM_STRING_FORMAT_MANAGER_H
