#include <codebase/net/EventLoopThread.h>
#include <codebase/net/EventLoop.h>
#include <codebase/base/Thread.h>

using namespace myth52125::net;
using namespace myth52125::base;



EventLoopThread::EventLoopThread(const ThreadCBFunc &func,const StrArg &name)
    :mp_loop(NULL),mb_exit(fasle),mb_start(false),
    m_thread(std::bind(&EventLoopThread::threadfunc,this),name),
    m_mutex(),m_cond(m_mutex),mq_cb(func)
{

}
EventLoopThread::~EventLoopThread()
{
    mb_exit = true;
    if(mp_loop != NULL)
    {
        mp_loop->quit();
        m_thread.join();
    }
}

EventLoop *EventLoopThread::start()
{
    assert(mb_start);
    mb_start=true;
    m_thread.start();

    {
        MutexLockGuard look(m_mutex);
        while(mp_loop == NULL)
        {
            cond.wait();
        }
    }
    return mp_loop;
}
 
void EventLoopThread::threadfunc()
{
    EventLoop loop;
    if(mq_cb)
    {
        mq_cb(&loop);
    }

    {
        MutexLockGuard look(m_mutex);
        mp_loop = &loop;
        m_cond.notify();
    }

    loop.loop();
    mp_loop = NULL;
}
