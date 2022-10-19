/**************************************************************
 * Peoject: Origin Platform
 * Description: 基础函数 -- 时间处理
 * Author: Li Yang
 * Date: 2022/08/07
 **************************************************************/
#ifndef C_LATFORM_TIME_H
#define C_LATFORM_TIME_H
#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __c_plus_plus

#define START_YEAR 1900
#define START_MONTH 1

#define FULL_TIME_STR_MIN_LEN 20
#define DATE_STR_MIN_LEN 11 // 1970-01-01\0
#define TIME_STR_MIN_LEN 9  // 09:00:00\0

typedef struct CPlatformTimeSt CPlatformTimeSt;
struct CPlatformTimeSt {
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint32_t hour;
    uint32_t minute;
    uint32_t second;
};

typedef enum BinRet {
    RET_OK,
    RET_ERR,
} BinRet;

void GetLocalTime(CPlatformTimeSt *timeSt);
BinRet GetDateStr(char *dateStr, uint32_t strLen, const CPlatformTimeSt *timeSt, const char dateSplit);
BinRet GetTimeStr(char *timeStr, uint32_t strLen, const CPlatformTimeSt *timeSt, const char timeSplit);
BinRet GetFullTimeStr(char *fullTimeStr, uint32_t strLen, const CPlatformTimeSt *timeSt, const char dateSplit, const char timeSplit);
BinRet GetLocalTimeStr(char *fullTimeStr, uint32_t strLen, const char dateSplit, const char timeSplit);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_LATFORM_TIME_H
