#ifndef _MYTH52125_TIMESTAMP_H_
#define _MYTH52125_TIMESTAMP_H_

#include <codebase/base/StringArg.h>
#include <stdint.h>
#include <stdio.h>

namespace myth52125
{
namespace base
{


class Timestamp
{
public:
    explicit Timestamp()
        :_microsecond(now())
        {}

    explicit Timestamp(int64_t micro)
        :_microsecond(micro)
        {}
private:
    int64_t _microsecond;
    int64_t now();
public:
    const static int microsecondPerSecond = 1000*1000;
    StringArg toString(bool showMicro= true);
    int64_t mirco()
    {
        return _microsecond;
    }
};

inline double timeDifference(Timestamp lhs, Timestamp rhs)
{
    return static_cast<double>((lhs.mirco()-rhs.mirco())/Timestamp::microsecondPerSecond);
}

class TimeSpend
{
public:
    TimeSpend()
        :_start(Timestamp())
    {
    }

    ~TimeSpend()
    {
        Timestamp tmp=Timestamp();
        printf("the time spend form start : %f \n",
            timeDifference(tmp,_start));
    }
private:
    Timestamp _start;

};




}



}



#endif
