/**************************************************************
 * Peoject: Origin Platform
 * Description: 基础函数 -- 时间处理
 * Author: Li Yang
 * Date: 2022/08/07
 **************************************************************/
#include "c_platform_time.h"
#include <time.h>
#include <string.h>

#define RETURN_ERR_IF_TRUE(boolVal) if (!(boolVal)) {printf("11111111 %d\n", __LINE__); return RET_ERR;}
#define RETURN_BIN(boolVal) return boolVal ? RET_OK : RET_ERR

void GetLocalTime(CPlatformTimeSt *timeSt)
{
    time_t now = time(0);
    struct tm* ltm = localtime(&now);
    timeSt->year = START_YEAR + (uint32_t)(ltm->tm_year);
    timeSt->month = START_MONTH + (uint32_t)(ltm->tm_mon);
    timeSt->day = (uint32_t)(ltm->tm_mday);
    timeSt->hour = (uint32_t)(ltm->tm_hour);
    timeSt->minute = (uint32_t)(ltm->tm_min);
    timeSt->second = (uint32_t)(ltm->tm_sec);
}

BinRet GetDateStr(char *dateStr, uint32_t strLen, const CPlatformTimeSt *timeSt, const char dateSplit)
{
    RETURN_ERR_IF_TRUE((dateStr == NULL) || (strLen < DATE_STR_MIN_LEN));

    int ret = 0;
    if (dateSplit == '\0') {
        ret = sprintf(dateStr, "%04u%02u%02u", timeSt->year, timeSt->month, timeSt->day);
    } else {
        ret = sprintf(dateStr, "%04u%c%02u%c%02u", timeSt->year, dateSplit, timeSt->month, dateSplit, timeSt->day);
    }
    dateStr[strLen - 1] = '\0';
    RETURN_BIN(ret > 0);
}

BinRet GetTimeStr(char *timeStr, uint32_t strLen, const CPlatformTimeSt *timeSt, const char timeSplit)
{
    RETURN_ERR_IF_TRUE((timeStr == NULL) || (strLen < TIME_STR_MIN_LEN));
    int ret = 0;
    if (timeSplit == '\0') {
        ret = sprintf(timeStr, "%02u%02u%02u", timeSt->hour, timeSt->minute, timeSt->second);
    } else {
        ret = sprintf(timeStr, "%02u%c%02u%c%02u", timeSt->hour, timeSplit, timeSt->minute, timeSplit, timeSt->second);
    }
    timeStr[strLen - 1] = '\0';
    RETURN_BIN(ret > 0);
}

BinRet GetFullTimeStr(char *fullTimeStr, uint32_t strLen, const CPlatformTimeSt *timeSt, const char dateSplit, const char timeSplit)
{
    RETURN_ERR_IF_TRUE((fullTimeStr == NULL) || (strLen < FULL_TIME_STR_MIN_LEN));

    uint32_t ret = 1;
    ret = GetDateStr(fullTimeStr, strLen, timeSt, dateSplit);
    RETURN_ERR_IF_TRUE(ret == RET_ERR);

    uint32_t dateStrLen = (uint32_t)(strlen(fullTimeStr));
    fullTimeStr[dateStrLen] = ' ';

    char *timeStr = fullTimeStr + dateStrLen + 1;
    uint32_t timeStrLen = strLen - dateStrLen - 1;
    ret = GetTimeStr(timeStr, timeStrLen, timeSt, timeSplit);
    RETURN_ERR_IF_TRUE(ret == RET_ERR);

    fullTimeStr[strLen - 1] = '\0';
    RETURN_BIN(ret > 0);
}

BinRet GetLocalTimeStr(char *fullTimeStr, uint32_t strLen, const char dateSplit, const char timeSplit)
{
    CPlatformTimeSt timeSt;
    GetLocalTime(&timeSt);
    return GetFullTimeStr(fullTimeStr, strLen, &timeSt, dateSplit, timeSplit);
}
