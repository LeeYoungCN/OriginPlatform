#include "log_print.h"
#include <stdarg.h>
#include <string.h>
#include "platform_time.h"

#define MAX_FORMAT_STR_LEN 256
#define MAX_LOG_STR_LEN 512

typedef struct LogPrintConfig LogPrintConfig;
struct LogPrintConfig {
    LogLevel minLogLevel;
    LogPrintScreen screenEnable;
    LogWriteFile writeEnable;
};

static LogPrintConfig g_logPrintCfg = {
    NO_PRINT, PRINT_DISABLE, WRITE_DISABLE
};

const char *GetFileName(const char* filePath);
void PrintScreen(const char *logStr);
const char *GetLogLevel(LogLevel level);

void LogPrintInit(LogLevel minPrintLevel, LogPrintScreen screenEnable, LogWriteFile writeFile)
{
    g_logPrintCfg.minLogLevel = minPrintLevel;
    g_logPrintCfg.screenEnable = screenEnable;
    g_logPrintCfg.writeEnable = writeFile;
}

void LogPrint(const uint32_t modId, LogLevel level, const char *fileName, uint32_t line, const char *fmt, ...)
{
    if (g_logPrintCfg.minLogLevel > level) {
        return;
    }
    int sprintfRet = 0;

    char formatStr[MAX_FORMAT_STR_LEN] = "\0";
    va_list argList;
    va_start(argList, fmt);
    sprintfRet = vsprintf(formatStr, fmt, argList);
    va_end(argList);
    if (sprintfRet < 0) {return;}

    char timeStr[100];
    GetLocalTimeStr(timeStr, 100, '-', ':');
    printf("time %s", timeStr);
    char logStr[MAX_LOG_STR_LEN] = "\0";
    sprintfRet = sprintf(logStr, "%s %s M%02u %s[%u] %s",
        timeStr, GetLogLevel(level), modId, GetFileName(fileName), line, formatStr);
    if (sprintfRet < 0) {return;}

    if (g_logPrintCfg.screenEnable == PRINT_ENABLE) {
        PrintScreen(logStr);
    }
    return;
}

const char *GetFileName(const char* filePath)
{
    if (filePath == NULL) {return "no name";}

    uint32_t len = (uint32_t)(strlen(filePath));
    uint32_t startPos = 0;
    for (uint32_t i = 0; i < len; i++) {
        if(filePath[i] == '\\' || filePath[i] == '/') {
            startPos = i;
        }
    }
    return (startPos > 0 ? filePath + startPos + 1 : filePath);
}

void PrintScreen(const char *logStr)
{
    if (logStr == NULL) {return;}
    printf("%s\n", logStr);
}

const char *GetLogLevel(LogLevel level)
{
    const char *logPrintLevelStr[] = {
        "DBG", "INF", "WARN", "ERR", "EVT", "NONE"
    };

    return logPrintLevelStr[(uint32_t)level];
}