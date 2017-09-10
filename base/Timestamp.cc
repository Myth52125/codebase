
#include <codebase/base/Debug.h>
#include <codebase/base/Timestamp.h>

#include <sys/time.h>
using namespace myth52125;
using namespace myth52125::base;


int64_t Timestamp::now()
{
    struct timeval tm;
    gettimeofday(&tm,NULL);
    int64_t sec = tm.tv_sec;
    return sec*Timestamp::microsecondPerSecond + tm.tv_usec; 
}

StringArg Timestamp::toString(bool showMicro)
{
    char buf[32];
    time_t sec = static_cast<time_t>(_microsecond/Timestamp::microsecondPerSecond);

    struct tm tm;
    gmtime_r(&sec,&tm);

    if(showMicro)
    {
        int micro = static_cast<int>(_microsecond % Timestamp::microsecondPerSecond);
        snprintf(buf,sizeof(buf),"%4d%02d%02d %02d:%02d:%02d.%06d",
                 tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
                 tm.tm_hour+8, tm.tm_min, tm.tm_sec,
                 micro);
    }else{
        snprintf(buf, sizeof(buf), "%4d%02d%02d %02d:%02d:%02d",
                tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
                tm.tm_hour +8 , tm.tm_min, tm.tm_sec);
    }
    return StringArg(buf);
}
