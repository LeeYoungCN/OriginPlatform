#ifndef STRING_PUBLIC_FUNC_H
#define STRING_PUBLIC_FUNC_H
#include <iostream>
#include "platform_public_typedef.h"

std::string GetNextStr(std::string::const_iterator &it, std::string::const_iterator &end, const char splitChar);
namespace UTF8{
uint64_t GetStrSpaceSize(const std::string str);
std::string GetStrWithSpace(const std::string str, const uint32_t maxLen, const uint32_t suffixSpceNum);
}

#endif // STRING_PUBLIC_FUNC_H
