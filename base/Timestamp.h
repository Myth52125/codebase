#ifndef _MYTH52125_TIMESTAMP_H_
#define _MYTH52125_TIMESTAMP_H_

#include <codebase/base/StringArg.h>

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
};







}



}



#endif
