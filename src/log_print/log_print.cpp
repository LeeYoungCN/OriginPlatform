/*
 * Peoject: Origin Platform
 * Description: 日志打印管理
 * Author: Li Yang
 * Date: 2022/08/07
 */
#include "log_print.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "platform_time.h"

using namespace OriginPlatform;

LogPrint &LogPrint::GetInstance()
{
    static LogPrint logPrintInst;
    return logPrintInst;
}

VOID LogPrint::LogPrintInit(LogLevel minPrintLevel, LogPrintScreen screenEnable, LogWriteFile writeFile)
{
    m_minPrintLevel = minPrintLevel;
    m_printScreen = screenEnable;
    m_writeFile = writeFile;
    m_isForbid = ((m_printScreen == LogPrintScreen::DISABLE) && (m_writeFile == LogWriteFile::DISABLE));
}

VOID LogPrint::Print(const UINT32 modId, LogLevel level, const CHAR *fileName, UINT32 line, const CHAR *fmt, ...)
{
    if ((m_isForbid) || (TO_U32(m_minPrintLevel) > TO_U32(level))) {
        return;
    }
    INT32 sprintfRet = 0;

    CHAR formatStr[MAX_FORMAT_STR_LEN] = "\0";
    va_list argList;
    va_start(argList, fmt);
    sprintfRet = vsprintf(formatStr, fmt, argList);
    va_end(argList);
    if (sprintfRet < 0) {return;}

    CHAR timeStr[FULL_TIME_STR_MIN_LEN] = "\0";
    GetLocalTimeStr(timeStr, FULL_TIME_STR_MIN_LEN);

    CHAR logStr[MAX_LOG_STR_LEN] = "\0";
    sprintfRet = sprintf(logStr, "%s %s M%02u %s[%u] %s",
        timeStr, GetLogLevel(level), modId, GetFileName(fileName), line, formatStr);
    if (sprintfRet < 0) {return;}

    if (m_printScreen == LogPrintScreen::ENABLE) {
        PrintScreen(logStr);
    }
}

const CHAR* LogPrint::GetFileName(const CHAR* filePath)
{
    if (filePath == nullptr) {return "no name";}

    UINT32 len = TO_U32(strlen(filePath));
    UINT32 startPos = 0;
    for (UINT32 i = 0; i < len; i++) {
        if(filePath[i] == '\\' || filePath[i] == '/') {
            startPos = i;
        }
    }
    return (startPos > 0 ? filePath + startPos + 1 : filePath);
}

VOID LogPrint::PrintScreen(const CHAR *logStr)
{
    if (logStr == nullptr) {return;}
    printf("%s\n", logStr);
}

const CHAR *LogPrint::GetLogLevel(LogLevel level)
{
    const CHAR *logPrintLevelStr[] = {
        "DBG", "INF", "WARN", "ERR", "EVT", "NONE"
    };

    return logPrintLevelStr[TO_U32(level)];
}
