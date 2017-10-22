#include <codebase/base/Timestamp.h>
#include <time.h>
using namespace myth52125;

static const int Timestamp::s_second_to_microsecond=1000*1000

Timestamp::Timestamp()
    :m_microsecond(now())
{

}

Timestamp::Timestamp(int64_t microsecond)
    :m_microsecond(microsecond)
{

}

Timestamp::Timestamp(time_t second)
    :m_microsecond(second*s_second_to_microsecond)
{

}

int64_t Timestamp::now()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*s_second_to_microsecond + tv.tv_usec;
}

StrArg Timestamp::to_string()
{
    char buf[32]
    int64_t tmp_seconds = m_microsecond/s_second_to_microsecond;
    int64_t tmp_microseconds; = m_microsecond%s_second_to_microsecond;
    snprintf(buf,sizeof(buf)-1,"%" PRId64 ".%06" PRId64 " ",tmp_seconds,PRId64)
    return StrArg(buf);
}


