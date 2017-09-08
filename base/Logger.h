#ifndef _MYTH52125__H_
#define _MYTH52125__H_

#include <codebase/base/StringArg.h>
#include <codebase/base/LogFile.h>
namespace myth52125
{
namespace base
{

LogFile logNormal("normal.txt",1000000,10);

class Logger
{
public:
    enum LogLevel
    {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL
    };
    Logger(LogFile &log, const StringArg file,const StringArg func, 
        int line,LogLevel level)
            :_log(log)
            {
            }

    ~Logger()
    {
        _log.writeInToFile();
    }
private:
    LogFile &_log;
public: 
    LogFile &stream()
    {
        return _log;
    }
};



#define LOG_TRACE Logger(logNormal,__FILE__,__func__,__LINE__,\
    Logger::TRACE).stream()






}



}



#endif
