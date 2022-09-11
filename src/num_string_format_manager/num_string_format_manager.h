#ifndef NUM_STRING_FORMAT_MANAGER_H
#define NUM_STRING_FORMAT_MANAGER_H
#include <iostream>
#include "platform_public_typedef.h"

enum class NumStrFmtEnum : UINT8 {
    NONE = 0,
    BIN = 2,
    OCT = 8,
    DEC = 10,
    HEX = 16,
};

class NumStringFormatManager {
public:
    static UINT32 moduleId;
    static const CHAR* moduleName;
public:
    // 数字与字符串转换
    static std::string   Num2Str(const UINT32 num, const NumStrFmtEnum numFmt, const UINT32 digitNum);
    static UINT32        Str2Num(const std::string &numStr);
    static UINT32        Str2Num(const std::string &numStr, const NumStrFmtEnum numFmt);
    // 字符串类型判断
    static NumStrFmtEnum JudgeNumFmt(const std::string &numStr);
    static BOOL          IsRightFmt(const std::string &numStr, const NumStrFmtEnum numFmt);
    // 字符串分解
    static BOOL          HasPrefix(const std::string &numStr, const NumStrFmtEnum numFmt);
    static std::string   GetNumPart(const std::string &numStr, const NumStrFmtEnum numFmt);
    static UINT32        NumPartLen(const std::string &numStr, const NumStrFmtEnum numFmt);

    static UINT32        Char2Num(const CHAR c, const NumStrFmtEnum numFmt);
};

#endif // NUM_STRING_FORMAT_MANAGER_H
