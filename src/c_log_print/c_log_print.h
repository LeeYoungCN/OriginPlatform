#ifndef C_LOG_PRINT_H
#define C_LOG_PRINT_H

#include <stdio.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif // __c_plus_plus

#define C_LOG(modInfo, level, fmt, ...) CLogPrint(modInfo, level, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#define C_LOG_DEBUG(modInfo, fmt, ...) C_LOG(modInfo, DEBUG, fmt, ##__VA_ARGS__)
#define C_LOG_INFO(modInfo, fmt, ...) C_LOG(modInfo, INFO, fmt, ##__VA_ARGS__)
#define C_LOG_WARNING(modInfo, fmt, ...) C_LOG(modInfo, WARNING, fmt, ##__VA_ARGS__)
#define C_LOG_ERROR(modInfo, fmt, ...) C_LOG(modInfo, ERROR, fmt, ##__VA_ARGS__)
#define C_LOG_EVENT(modInfo, fmt, ...) C_LOG(modInfo, EVENT, fmt, ##__VA_ARGS__)

typedef enum CLogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    EVENT,
    NO_PRINT
} CLogLevel;

typedef enum CLogPrintScreen {
    PRINT_ENABLE = 0,
    PRINT_DISABLE,
} CLogPrintScreen;

typedef enum CLogWriteFile {
    WRITE_ENABLE = 0,
    WRITE_DISABLE,
} CLogWriteFile;

void CLogPrintInit(CLogLevel minPrintLevel, CLogPrintScreen screenEnable, CLogWriteFile writeFile);
void CLogPrint(const uint32_t modId, CLogLevel level, const char *fileName, uint32_t line, const char *fmt, ...);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_LOG_PRINT_H
