/**************************************************************
 * Peoject: Origin Platform
 * Description: 基础函数 -- 时间处理
 * Author: Li Yang
 * Date: 2022/08/07
 **************************************************************/
#include "platform_public_typedef.h"

namespace OriginPlatform {
    const UINT32 START_YEAR = 1900;
    const UINT32 START_MONTH = 1;

    const UINT32 FULL_TIME_STR_MIN_LEN = 20;
    const UINT32 DATE_STR_MIN_LEN = 11; // 1970-01-01\0
    const UINT32 TIME_STR_MIN_LEN = 9;  // 09:00:00\0
}
struct PlatformTimeSt {
    UINT32 year = 1970;
    UINT32 month = 1;
    UINT32 day = 1;
    UINT32 hour = 0;
    UINT32 minute = 0;
    UINT32 second = 0;
};

VOID GetLocalTime(PlatformTimeSt &timeSt);
BinRet GetDateStr(CHAR *dateStr, UINT32 strLen, const PlatformTimeSt &timeSt, const CHAR dateSplit = '-');
BinRet GetTimeStr(CHAR *timeStr, UINT32 strLen, const PlatformTimeSt &timeSt, const CHAR timeSplit = ':');
BinRet GetFullTimeStr(CHAR *fullTimeStr, UINT32 strLen, const PlatformTimeSt &timeSt, const CHAR dateSplit = '-', const CHAR timeSplit = ':');
BinRet GetLocalTimeStr(CHAR *fullTimeStr, UINT32 strLen, const CHAR dateSplit = '-', const CHAR timeSplit = ':');
