/*
 * Project: Origin Platform
 * Description: 基础函数 -- 时间处理
 * Author: Li Yang
 * Date: 2022/08/07
 */
#ifndef PLATFORM_TIME_H
#define PLATFORM_TIME_H
#include <stdio.h>
#include <stdint.h>
#include "platform_public_typedef.h"

#define START_YEAR 1900
#define START_MONTH 1

#define FULL_TIME_STR_MIN_LEN 20
#define DATE_STR_MIN_LEN 11 // 1970-01-01\0
#define TIME_STR_MIN_LEN 9  // 09:00:00\0

#ifdef __cplusplus
extern "C" {
#endif // __c_plus_plus

typedef struct PlatformTimeSt PlatformTimeSt;
struct PlatformTimeSt {
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint32_t hour;
    uint32_t minute;
    uint32_t second;
};

void GetLocalTime(PlatformTimeSt *timeSt);
ErrorCode GetDateStr(char *dateStr, uint32_t strLen, const PlatformTimeSt *timeSt, const char dateSplit);
ErrorCode GetTimeStr(char *timeStr, uint32_t strLen, const PlatformTimeSt *timeSt, const char timeSplit);
ErrorCode GetFullTimeStr(char *fullTimeStr, uint32_t strLen, const PlatformTimeSt *timeSt, const char dateSplit, const char timeSplit);
ErrorCode GetLocalTimeStr(char *fullTimeStr, uint32_t strLen, const char dateSplit, const char timeSplit);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // PLATFORM_TIME_H
