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
#include <cstring>

using namespace OriginPlatform;

VOID GetLocalTime(PlatformTimeSt &timeSt)
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    timeSt.year = START_YEAR + TO_U32(ltm->tm_year);
    timeSt.month = START_MONTH + TO_U32(ltm->tm_mon);
    timeSt.day = TO_U32(ltm->tm_mday);
    timeSt.hour = TO_U32(ltm->tm_hour);
    timeSt.minute = TO_U32(ltm->tm_min);
    timeSt.second = TO_U32(ltm->tm_sec);
}

BinRet GetDateStr(CHAR *dateStr, UINT32 strLen, const PlatformTimeSt &timeSt, const CHAR dateSplit)
{
    RETURN_ERR_IF_TRUE((dateStr == nullptr) || (strLen < DATE_STR_MIN_LEN));

    INT32 ret = 0;

    if (dateSplit == '\0') {
        ret = sprintf(dateStr, "%04u%02u%02u", timeSt.year, timeSt.month, timeSt.day);
        dateStr[strLen - 1] = '\0';
        RETURN_BIN_RET(ret > 0);
    }

    ret = sprintf(dateStr, "%04u-%02u-%02u", timeSt.year, timeSt.month, timeSt.day);
    for (UINT32 i = 0; i < strLen; i++) {
        if (dateStr[i] == '-') {
            dateStr[i] = dateSplit;
        }
    }
    dateStr[strLen - 1] = '\0';
    RETURN_BIN_RET(ret > 0);
}

BinRet GetTimeStr(CHAR *timeStr, UINT32 strLen, const PlatformTimeSt &timeSt, const CHAR timeSplit)
{
    RETURN_ERR_IF_TRUE((timeStr == nullptr) || (strLen < TIME_STR_MIN_LEN));
    INT32 ret = 0;
    if (timeSplit == '\0') {
        ret = sprintf(timeStr, "%02u%02u%02u", timeSt.hour, timeSt.minute, timeSt.second);
        timeStr[strLen - 1] = '\0';
        RETURN_BIN_RET(ret > 0);
    }

    ret = sprintf(timeStr, "%02u:%02u:%02u", timeSt.hour, timeSt.minute, timeSt.second);
    for (UINT32 i = 0; i < strLen; i++) {
        if (timeStr[i] == '-') {
            timeStr[i] = timeSplit;
        }
    }
    timeStr[strLen - 1] = '\0';
    RETURN_BIN_RET(ret > 0);
}

BinRet GetFullTimeStr(CHAR *fullTimeStr, UINT32 strLen, const PlatformTimeSt &timeSt, const CHAR dateSplit, const CHAR timeSplit)
{
    RETURN_ERR_IF_TRUE((fullTimeStr == nullptr) || (strLen < FULL_TIME_STR_MIN_LEN));

    BinRet ret = BinRet::OK;
    ret = GetDateStr(fullTimeStr, strLen, timeSt, dateSplit);
    RETURN_ERR_IF_TRUE(!IS_OK(ret));

    UINT32 dateStrLen = TO_U32(strlen(fullTimeStr));
    fullTimeStr[dateStrLen] = ' ';

    CHAR *timeStr = fullTimeStr + dateStrLen + 1;
    UINT32 timeStrLen = strLen - dateStrLen - 1;
    ret = GetTimeStr(timeStr, timeStrLen, timeSt, timeSplit);
    RETURN_ERR_IF_TRUE(!IS_OK(ret));

    fullTimeStr[strLen - 1] = '\0';
    return BIN_OK;
}

BinRet GetLocalTimeStr(CHAR *fullTimeStr, UINT32 strLen, const CHAR dateSplit, const CHAR timeSplit)
{
    PlatformTimeSt timeSt;
    GetLocalTime(timeSt);
    return GetFullTimeStr(fullTimeStr, strLen, timeSt, dateSplit, timeSplit);
}
