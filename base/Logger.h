#ifndef _MYTH52125__H_
#define _MYTH52125__H_

#include <codebase/base/StringArg.h>
#include <codebase/base/LogStream.h>
#include <codebase/base/Timestamp.h>
#include <codebase/base/EveryThread.h>

// extern __thread  char _threadName[32];
// extern __thread  pid_t _threadTid;

namespace myth52125
{
namespace base
{



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
    Logger(const StringArg file,const StringArg func, 
        int line,LogLevel level)
            {
            }

    ~Logger()
    {
        _log.printf();
    }
private:
    LogStream _log;
public: 
    LogStream &stream()
    {
        _log<<Timestamp().toString()
            <<" thread : "<<static_cast<int>(thread::getTid())
            <<" thread name : "<<thread::_threadName<<" | "; 
        return _log;
    }
};



#define LOG_TRACE Logger(__FILE__,__func__,__LINE__,\
    Logger::TRACE).stream()






}



}



#endif
