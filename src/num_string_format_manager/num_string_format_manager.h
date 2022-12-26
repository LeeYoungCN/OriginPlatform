#ifndef NUM_STRING_FORMAT_MANAGER_H
#define NUM_STRING_FORMAT_MANAGER_H
#include <iostream>
#include "platform_public_typedef.h"

enum class NumStrFmtEnum : uint8_t {
    NONE = 0,
    BIN = 2,
    OCT = 8,
    DEC = 10,
    HEX = 16,
};

class NumStringFormatManager {
public:
    static uint32_t moduleId;
    static const char *moduleName;
public:
    // 数字与字符串转换
    static std::string   Num2Str(const uint32_t num, const NumStrFmtEnum numFmt, const uint32_t digitNum);
    static uint32_t        Str2Num(const std::string &numStr);
    static uint32_t        Str2Num(const std::string &numStr, const NumStrFmtEnum numFmt);
    // 字符串类型判断
    static NumStrFmtEnum JudgeNumFmt(const std::string &numStr);
    static bool          IsRightFmt(const std::string &numStr, const NumStrFmtEnum numFmt);
    // 字符串分解
    static bool          HasPrefix(const std::string &numStr, const NumStrFmtEnum numFmt);
    static std::string   GetNumPart(const std::string &numStr, const NumStrFmtEnum numFmt);
    static uint32_t        NumPartLen(const std::string &numStr, const NumStrFmtEnum numFmt);

    static uint32_t        Char2Num(const char c, const NumStrFmtEnum numFmt);
};

#endif // NUM_STRING_FORMAT_MANAGER_H
