#ifndef _MYTH52125_TIMESTAMP_H_
#define _MYTH52125_TIMESTAMP_H_

#include <codebase/base/StrArg.h>
#include <time.h>
namespace myth52125
{


class Timestamp
{
public:
    Timestamp();
    Timestamp(int64_t);
    Timestamp(time_t);

private:
    int64_t m_microsecond;
    int64_t now();

public:
    // void swap();
    StrArg to_string();
    bool valid();
    int64_t microsecond();

    static const int s_second_to_microsecond;
};


inline bool operator==(Timestamp lhs,Timestamp rhs)
{
    return lhs.microsecond()==rhs.microsecond;
}

inline bool operator<(Timestamp lhs,Timestamp rhs)
{
    return lhs.microsecond()<rhs.microsecond;
    
}
inline bool operator>(Timestamp lhs,Timestamp rhs)
{
    return lhs.microsecond()>rhs.microsecond;
}

}

#endif  //_MYTH52125_TIMESTAMP_H_