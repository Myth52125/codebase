#ifndef _MYTH52125_EVENTLOOPTHREAD_H_
#define _MYTH52125_EVENTLOOPTHREAD_H_

#include <codebase/base/StringArg.h>
#include <boost/function.hpp>
#include <codebase/base/MutexLock.h>
#include <codebase/base/Condition.h>
#include <codebase/base/Thread.h>



namespace myth52125
{
namespace net
{
using namespace myth52125::base;

class EventLoop;

class EventLoopThread
{
public:
    typedef boost::function<void (EventLoop *)> InitFunc;
    EventLoopThread(const InitFunc &cb,const StringArg &name); 
    ~EventLoopThread();

private:
    InitFunc _cb;
    StringArg _name;
    MutexLock _mutex;
    EventLoop *_loop;
    Thread _thread;
    Condition _con;
    void runInThread();
public:
    EventLoop* start();


};







}



}



#endif
