#include "string_public_func.h"
#include "platform_public_macro.h"
using namespace std;

string GetNextStr(string::const_iterator &it, string::const_iterator &end, const char splitChar)
{
    string retStr = "";
    while (*it == splitChar && *it != '\0' && it != end) {
        it++;
    }
    while (*it != splitChar && *it != '\0' && it != end) {
        retStr += *it++;
    }
    return retStr;
}

namespace UTF8 {
const uint32_t CHINESE_WORD_SPACE_NUM = 2;
const uint32_t CHINESE_WORD_CHAR_NUM  = 3;
const uint8_t  UTF8_MULTI_CHAR_FLAG = 0x80;

uint64_t GetStrSpaceSize(const std::string str)
{
    uint64_t size = 0; 
    for(uint32_t i = 0; str[i] != '\0';) {
        if (str[i] & UTF8_MULTI_CHAR_FLAG) {
            size += CHINESE_WORD_SPACE_NUM;
            i    += CHINESE_WORD_CHAR_NUM;
        } else {
            size++;
            i++;
        }
    }
    return size;
}

string GetStrWithSpace(const std::string str, const uint32_t maxLen, const uint32_t suffixSpceNum)
{
    uint64_t tmpNum = GetStrSpaceSize(str);
    uint64_t spaceNum = suffixSpceNum + (maxLen > tmpNum ? maxLen - tmpNum : 0);

    return str + string(spaceNum, ' ');
}
}