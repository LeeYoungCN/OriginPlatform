/**************************************************************
 * Peoject: Origin Platform
 * Description: 基础函数 -- 时间处理
 * Author: Li Yang
 * Date: 2022/08/07
 **************************************************************/
#include "platform_time.h"
#include "platform_public_macro.h"
#include <ctime>
#include <stdio.h>

namespace {
    const UINT32 START_YEAR = 1900;
    const UINT32 START_MONTH = 1;
}

VOID GetLocalTime(PlatformTimeSt &timeSt)
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    timeSt.year = START_YEAR + ltm->tm_year;
    timeSt.month = START_MONTH + ltm->tm_mon;
    timeSt.day = ltm->tm_mday;
    timeSt.hour = ltm->tm_hour;
    timeSt.minute = ltm->tm_min;
    timeSt.second = ltm->tm_sec;
}

BinRet GetTimeStr(CHAR *timeStr, UINT32 strLen, const PlatformTimeSt &timeSt)
{
    if ((timeStr == nullptr) || (strLen < TIME_STR_MIN_LEN)) {
        return OP_ERR;
    }
    INT32 ret = sprintf_s(timeStr, strLen, "%04u-%02u-%02u %02u:%02u:%02u",
        timeSt.year, timeSt.month, timeSt.day, timeSt.hour, timeSt.minute, timeSt.second);
    timeStr[strLen - 1] = '\0';
    return (ret > 0 ? OP_OK : OP_ERR);
}

BinRet GetLocalTimeStr(CHAR *timeStr, UINT32 strLen)
{
    PlatformTimeSt timeSt;
    GetLocalTime(timeSt);
    return GetTimeStr(timeStr, strLen, timeSt);
}
