/**************************************************************
 * Peoject: Origin Platform
 * Description: 基础函数 -- 时间处理
 * Author: Li Yang
 * Date: 2022/08/07
 **************************************************************/
#include "platform_public_typedef.h"

struct PlatformTimeSt {
    UINT32 year = 1970;
    UINT32 month = 1;
    UINT32 day = 1;
    UINT32 hour = 0;
    UINT32 minute = 0;
    UINT32 second = 0;
};

const UINT32 TIME_STR_MIN_LEN = 20;

VOID GetLocalTime(PlatformTimeSt &timeSt);
BinRet GetTimeStr(CHAR *timeStr, UINT32 strLen, const PlatformTimeSt &timeSt);
BinRet GetLocalTimeStr(CHAR *timeStr, UINT32 strLen);
