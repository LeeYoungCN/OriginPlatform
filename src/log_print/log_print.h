/*
 * Project: Origin Platform
 * Description: 基础函数 -- LOG打印
 * Author: Li Yang
 * Date: 2022/08/07
 */
#ifndef LOG_PRINT_H
#define LOG_PRINT_H

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif // __c_plus_plus

#define LOG(modInfo, level, fmt, ...) LogPrint(modInfo, level, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#define LOG_DEBUG(modInfo, fmt, ...) LOG(modInfo, DEBUG, fmt, ##__VA_ARGS__)
#define LOG_INFO(modInfo, fmt, ...) LOG(modInfo, INFO, fmt, ##__VA_ARGS__)
#define LOG_WARNING(modInfo, fmt, ...) LOG(modInfo, WARNING, fmt, ##__VA_ARGS__)
#define LOG_ERROR(modInfo, fmt, ...) LOG(modInfo, ERROR, fmt, ##__VA_ARGS__)
#define LOG_EVENT(modInfo, fmt, ...) LOG(modInfo, EVENT, fmt, ##__VA_ARGS__)

typedef enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    EVENT,
    NO_PRINT
} LogLevel;

typedef enum LogPrintScreen {
    PRINT_ENABLE = 0,
    PRINT_DISABLE,
} LogPrintScreen;

typedef enum LogWriteFile {
    WRITE_ENABLE = 0,
    WRITE_DISABLE,
} LogWriteFile;

void LogPrintInit(LogLevel minPrintLevel, LogPrintScreen screenEnable, LogWriteFile writeFile);
void LogPrint(const uint32_t modId, LogLevel level, const char *fileName, uint32_t line, const char *fmt, ...);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LOG_PRINT_H
