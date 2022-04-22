#include <string>
#include <fstream>
#pragma once

enum class LogType : unsigned int
{
    INF = 0,
    WARN = 1,
    ERR = 2,
    DBG = 3,
};

class Logger : public std::exception
{
public:

    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&) = delete;
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;

    void log(const std::string& p_fileInfo,
        const std::string& p_line,
        const std::string& p_informationMessage,
        LogType p_logType);

    void setLogType(LogType p_logType);

    const std::string& fetchConsoleLogs();

    static Logger& getInstance();
private:
    Logger();
    ~Logger();
    std::string prepareLogFile();
    std::string getCurrentTime();
    std::string getLogType(LogType p_logType);

    LogType s_logType;
    std::ofstream m_logFile;
    std::string m_logToConsole;
};

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define __FILENAME__ strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__
#define FILE_INFO  __FILENAME__
#define LINES TOSTRING(__LINE__)

#define LOG(msg, type) Logger::getInstance().log(FILE_INFO, LINES, msg, type) 
#define SET_LOG_TYPE(type) Logger::getInstance().setLogType(type)
