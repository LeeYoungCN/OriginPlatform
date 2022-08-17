/**************************************************************
 * Peoject: Origin Platform
 * Description: 日志打印管理
 * Author: Li Yang
 * Date: 2022/08/07
 **************************************************************/
#include "log_print.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "platform_time.h"

namespace {
    const UINT32 MAX_FORMAT_STR_LEN = 256;
    const CHAR *g_logPrintLevelStr[] = {
        "DBG", "INF", "WARN", "ERR", "EVT"
    };
};
VOID LogPrint::LogPrintInit(LogLevel minPrintLevel, LogPrintScreen screenEnable, LogWriteFile writeFile)
{
    m_minPrintLevel = minPrintLevel;
    m_printScreen = screenEnable;
    m_writeFile = writeFile;
    m_isForbid = ((m_printScreen == LogPrintScreen::DISABLE) && (m_writeFile == LogWriteFile::DISABLE));
}

VOID LogPrint::Print(const CHAR *modName, LogLevel level, const CHAR *fileName, UINT32 line, const CHAR *fmt, ...)
{
    if (m_isForbid || (TO_U32(m_minPrintLevel) > TO_U32(level))) {
        return;
    }
    INT32 sprintfRet = 0;

    CHAR formatStr[MAX_FORMAT_STR_LEN] = "\0";
    va_list argList;
    va_start(argList, fmt);
    sprintfRet = vsprintf_s(formatStr, MAX_FORMAT_STR_LEN, fmt, argList);
    va_end(argList);
    if (sprintfRet < 0) {return;}

    CHAR timeStr[TIME_STR_MIN_LEN] = "\0";
    GetLocalTimeStr(timeStr, TIME_STR_MIN_LEN);

    CHAR logStr[MAX_FORMAT_STR_LEN] = "\0";
    sprintfRet = sprintf_s(logStr, MAX_FORMAT_STR_LEN, "%s %s %s %s[%u] %s",
        timeStr, modName, g_logPrintLevelStr[TO_U32(level)],
        GetFileName(fileName), line, formatStr);
    if (sprintfRet < 0) {return;}

    if (m_printScreen == LogPrintScreen::ENABLE) {
        PrintScreen(logStr);
    }
}

const CHAR* LogPrint::GetFileName(const CHAR* filePath)
{
    if (filePath == nullptr) {return "no name";}

    UINT32 len = strlen(filePath);
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