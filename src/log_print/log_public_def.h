/**************************************************************
 * Peoject: Origin Platform
 * Description: 日志打印定义
 * Author: Li Yang
 * Date: 2022/08/07
 **************************************************************/
#ifndef LOG_PUBLIC_DEF_H
#define LOG_PUBLIC_DEF_H
#include "platform_public_typedef.h"
#include "platform_public_macro.h"

enum class LogLevel : UINT8 {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    EVENT,
    NO_PRINT,
};

enum class LogPrintScreen : UINT8 {
    ENABLE = 0,
    DISABLE,
};

enum class LogWriteFile : UINT8 {
    ENABLE = 0,
    DISABLE,
};

#define LOG(modInfo, level, fmt, ...) INS(LogPrint).Print(modInfo, level, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#define LOG_DEBUG(modInfo, fmt, ...) LOG(modInfo, LogLevel::DEBUG, fmt, ##__VA_ARGS__)
#define LOG_INFO(modInfo, fmt, ...) LOG(modInfo, LogLevel::INFO, fmt, ##__VA_ARGS__)
#define LOG_WARNING(modInfo, fmt, ...) LOG(modInfo, LogLevel::WARNING, fmt, ##__VA_ARGS__)
#define LOG_ERROR(modInfo, fmt, ...) LOG(modInfo, LogLevel::ERROR, fmt, ##__VA_ARGS__)
#define LOG_EVENT(modInfo, fmt, ...) LOG(modInfo, LogLevel::EVENT, fmt, ##__VA_ARGS__)

#endif // LOG_PUBLIC_DEF_H
