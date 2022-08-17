/**************************************************************
 * Peoject: Origin Platform
 * Description: 日志打印管理
 * Author: Li Yang
 * Date: 2022/08/07
 **************************************************************/
#ifndef LOG_PRINT_H
#define LOG_PRINT_H
#include "platform_public_typedef.h"
#include "log_public_def.h"

class LogPrint {
public:
    static LogPrint &GetInstance()
    {
        static LogPrint logPrintInst;
        return logPrintInst;
    }

    VOID LogPrintInit(LogLevel minPrintLevel, LogPrintScreen screenEnable, LogWriteFile writeFile);
    VOID Print(const CHAR *modName, LogLevel level, const CHAR *fileName, UINT32 line, const CHAR *fmt, ...);

private:
    LogPrint() = default;
    ~LogPrint() = default;
    const CHAR* GetFileName(const CHAR* filePath);
    VOID PrintScreen(const CHAR *logStr);
    bool m_isForbid = false;
    LogLevel m_minPrintLevel = LogLevel::NO_PRINT;
    LogPrintScreen m_printScreen = LogPrintScreen::DISABLE;
    LogWriteFile   m_writeFile = LogWriteFile::DISABLE;
};

#endif // LOG_PRINT_H
