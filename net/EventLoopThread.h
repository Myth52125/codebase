#ifndef MYTH52125_EVENTLOOPTHREAD_H
#define MYTH52125_EVENTLOOPTHREAD_H

#include <codebase/base/StrArg.h>
#include <codebase/base/Thread.h>
#include <codebase/base/MutexLock.h>
#include <codebase/base/Condition.h>

#include <functional>
namespace myth52125
{
namespace net
{
using namespace myth52125::base;

class EventLoop;
class EventLoopThread
{
public:
    typedef std::function<void (EventLoop *)> ThreadCBFunc;
    EventLoopThread(const ThreadCBFunc &func=ThreadCBFunc(),const StrArg &name=StrArg("No name"));
    ~EventLoopThread();

private:
    EventLoop *mp_loop;
    ThreadCBFunc mq_cb;
    Thread m_thread;
    MutexLock m_mutex;
    Condition m_cond;
    bool mb_exit;
    bool mb_start;
    void threadfunc();
    
public:
    EventLoop *start();

};
}

}

#endif  //MYTH52125_EVENTLOOPTHREAD_H