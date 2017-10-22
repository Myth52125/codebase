#ifndef _MYTH52125_TIMESTAMP_H_
#define _MYTH52125_TIMESTAMP_H_

#include <codebase/base/StrArg.h>
#include <time.h>
namespace myth52125
{


class Timestamp
{
public:
    Timestamp()
        :
    {

    }
    Timestamp(int64_t);
    Rimestamp(time_t)

private:
    int64_t mircrosecond;
    int64_t now();

public:
    // void swap();
    StrArg to_string();
    
    bool valid();
    
    int64_t m_microsecond();

    static const int second_to_microsecond;

};

}

#endif  //_MYTH52125_TIMESTAMP_H_