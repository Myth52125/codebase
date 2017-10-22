#ifndef _MYTH52125_TIMER_H_
#define _MYTH52125_TIMER_H_

// #include <codebase/net/>
#include <functional>
#include <codebase/net/Timerstamp.h>
namespace myth52125
{

namespace net
{

typedef std::function<void ()> TimerCallback;
// typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
// typedef std::function<void (const TcpConnectionPtr&)> ConnectionCallback;
// typedef std::function<void (const TcpConnectionPtr&)> CloseCallback;
// typedef std::function<void (const TcpConnectionPtr&)> WriteCompleteCallback;
// typedef std::function<void (const TcpConnectionPtr&, size_t)> HighWaterMarkCallback;

class Timer 
{
public:
    Timer(const TimerCallback &cb,Timestamp now_time ,int64_t interval = 0)
        :m_callback(cb),m_expiration(now_time),m_interval(interval),
        mb_repeat(interval == 0)
    {
        
    }

private:
    const TimerCallback m_callback;
    Timerstamp m_expiration;
    const int64_t m_interval;
    bool mb_repeat;

public:
    void run_callback() const
    {
        m_callback();
    }

    Timestamp expiration() const
    {
        return m_expiration;
    }

    void restart(Timestamp now_time)
    {
        if(mb_repeat)
        {
            m_expiration = Timestamp(now_time.microsecond()+m_interval);
        }else{
            m_expiration = Timestamp(0);
        }
    }
};
}
}

#endif  //_MYTH52125_TIMER_H_