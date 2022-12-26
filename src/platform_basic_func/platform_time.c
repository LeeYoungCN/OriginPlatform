/*
 * Project: Origin Platform
 * Description: 基础函数 -- 时间处理
 * Author: Li Yang
 * Date: 2022/08/07
 */

#include "platform_time.h"
#include <time.h>
#include <string.h>

void GetLocalTime(PlatformTimeSt *timeSt)
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

ErrorCode GetDateStr(char *dateStr, uint32_t strLen, const PlatformTimeSt *timeSt, const char dateSplit)
{
    if ((dateStr == NULL) || (strLen < DATE_STR_MIN_LEN)) {
        return ERROR_SYS_ERR;
    }

    int ret = 0;
    if (dateSplit == '\0') {
        ret = sprintf(dateStr, "%04u%02u%02u", timeSt->year, timeSt->month, timeSt->day);
    } else {
        ret = sprintf(dateStr, "%04u%c%02u%c%02u", timeSt->year, dateSplit, timeSt->month, dateSplit, timeSt->day);
    }
    dateStr[strLen - 1] = '\0';

    return (ret > 0 ? ERROR_SYS_OK : ERROR_SYS_ERR);
}

ErrorCode GetTimeStr(char *timeStr, uint32_t strLen, const PlatformTimeSt *timeSt, const char timeSplit)
{
    if ((timeStr == NULL) || (strLen < TIME_STR_MIN_LEN)) {
        return ERROR_SYS_ERR;
    }
    int ret = 0;
    if (timeSplit == '\0') {
        ret = sprintf(timeStr, "%02u%02u%02u", timeSt->hour, timeSt->minute, timeSt->second);
    } else {
        ret = sprintf(timeStr, "%02u%c%02u%c%02u", timeSt->hour, timeSplit, timeSt->minute, timeSplit, timeSt->second);
    }
    timeStr[strLen - 1] = '\0';
    return (ret > 0 ? ERROR_SYS_OK : ERROR_SYS_ERR);
}

ErrorCode GetFullTimeStr(char *fullTimeStr, uint32_t strLen, const PlatformTimeSt *timeSt, const char dateSplit, const char timeSplit)
{
    if ((fullTimeStr == NULL) || (strLen < FULL_TIME_STR_MIN_LEN)) {
        return ERROR_SYS_ERR;
    }

    uint32_t ret = 1;
    ret = GetDateStr(fullTimeStr, strLen, timeSt, dateSplit);
    if (ret == ERROR_SYS_ERR) {
        return ERROR_SYS_ERR;
    }

    uint32_t dateStrLen = (uint32_t)(strlen(fullTimeStr));
    fullTimeStr[dateStrLen] = ' ';

    char *timeStr = fullTimeStr + dateStrLen + 1;
    uint32_t timeStrLen = strLen - dateStrLen - 1;
    ret = GetTimeStr(timeStr, timeStrLen, timeSt, timeSplit);
    if (ret == ERROR_SYS_ERR) {
        return ERROR_SYS_ERR;
    }

    fullTimeStr[strLen - 1] = '\0';
    return (ret > 0 ? ERROR_SYS_OK : ERROR_SYS_ERR);
}

ErrorCode GetLocalTimeStr(char *fullTimeStr, uint32_t strLen, const char dateSplit, const char timeSplit)
{
    PlatformTimeSt timeSt;
    GetLocalTime(&timeSt);
    return GetFullTimeStr(fullTimeStr, strLen, &timeSt, dateSplit, timeSplit);
}
