#include "module_log_print.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctime>
#include <iostream>
using namespace std;

std::string GetTime();
const CHAR* GetFileName(const CHAR* filePath);

VOID LogPrint(UINT32 modId, LogLevel level, const CHAR *fileName, UINT32 line, const CHAR *fmt, ...)
{
    printf("%s M%u %s[%u] ", GetTime().c_str(), modId, GetFileName(fileName), line);
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);

    printf("\n");
}

VOID LogPrint(const CHAR *modName, LogLevel level, const CHAR *fileName, UINT32 line, const CHAR *fmt, ...)
{
    printf("%s [%s] %s[%u] ", GetTime().c_str(), modName, GetFileName(fileName), line);
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);

    printf("\n");
}

const CHAR* GetFileName(const CHAR* filePath)
{
    if (filePath == nullptr) {
        return "no name";
    }

    UINT32 len = strlen(filePath);
    UINT32 startPos = 0;
    for (UINT32 i = 0; i < len; i++) {
        if(filePath[i] == '\\' || filePath[i] == '/') {
            startPos = i;
        }
    }

    return (startPos > 0 ? filePath + startPos + 1 : filePath);
}

std::string GetTime()
{
    std::string timeStr;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    auto toStr = [](int time_data, std::string symbol) -> std::string {
        std::string ret;
        if (time_data < 10) {
            ret += "0";
        }
        ret += to_string(time_data) + symbol;
        return ret;
    };
    timeStr += toStr(1900 + ltm->tm_year, "-");
    timeStr += toStr(ltm->tm_mon + 1,  "-");
    timeStr += toStr(ltm->tm_mday, " ");
    timeStr += toStr(ltm->tm_hour, ":");
    timeStr += toStr(ltm->tm_min,  ":");
    timeStr += toStr(ltm->tm_sec,  "");
    return timeStr;
}