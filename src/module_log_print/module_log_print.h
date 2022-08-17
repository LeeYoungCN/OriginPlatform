#ifndef LOG_PRINT_H
#define LOG_PRINT_H
#include "public_typedef.h"

#define MOD_LOG(modInfo, level, fmt, ...) LogPrint(modInfo, level, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#define MOD_LOG_DEBUG(modInfo, fmt, ...) MOD_LOG(modInfo, LogLevel::DEBUG, fmt, ##__VA_ARGS__)
#define MOD_LOG_INFO(modInfo, fmt, ...) MOD_LOG(modInfo, LogLevel::INFO, fmt, ##__VA_ARGS__)
#define MOD_LOG_WARNING(modInfo, fmt, ...) MOD_LOG(modInfo, LogLevel::WARNING, fmt, ##__VA_ARGS__)
#define MOD_LOG_ERROR(modInfo, fmt, ...) MOD_LOG(modInfo, LogLevel::ERROR, fmt, ##__VA_ARGS__)
#define MOD_LOG_EVENT(modInfo, fmt, ...) MOD_LOG(modInfo, LogLevel::EVENT, fmt, ##__VA_ARGS__)

enum class LogLevel : UINT8 {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    EVENT,
    LEVEL_NUM
};

VOID LogPrint(UINT32 u16ModId, LogLevel level, const CHAR *fileName, UINT32 line, const CHAR *fmt, ...);
VOID LogPrint(const CHAR *modName, LogLevel level, const CHAR *fileName, UINT32 line, const CHAR *fmt, ...);

#endif // LOG_PRINT_H