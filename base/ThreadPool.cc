
#include <codebase/base/File.h>
#include <codebase/base/Debug.h>
#include <codebase/base/ThreadPool.h>
#include <iostream>
// #include <EveryThread.h>

#include <boost/bind.hpp>

using namespace myth52125;
using namespace myth52125::base;

ThreadPool::ThreadPool(size_t num,StringArg name)
    :_threadNum(num),_name(name),
    _started(false),_stoped(false),
    _maxTaskSize(num*10),
    _mutex(),_canAdd(_mutex),_canTake(_mutex)
{
    std::cout<<"mutex :"<<_mutex.mutex()<<std::endl;
    
}

void ThreadPool::runInThread()
{
    if(_cb)
    {
        _cb();
    }
    Task task = takeTask();
    if(task)
    {
        task();
    }
}

void ThreadPool::start()
{
    _started=true;
    _threads.reserve(_threadNum);
    for(int i=0;i<_threadNum;i++)
    {
        char id[32];
        snprintf(id,sizeof(id),"%s : %d",_name.c_str(),i+1);
        _threads.push_back(new Thread(boost::bind(&ThreadPool::runInThread,this),id));
        _threads[i].start();
    }
}

void ThreadPool::stop()
{
    {

    }
}

bool ThreadPool::fulled()
{
    return _tasks.size()>_maxTaskSize;
}

ThreadPool::Task ThreadPool::takeTask()
{
    MutexLockGuard lock(_mutex);
    while(_tasks.empty())
    {
        printf("take wait()");
        _canTake.wait();
    }
    Task task;
    if(!_tasks.empty())
    {
        task=_tasks.front();
        _tasks.pop_back();
        _canAdd.notifyAll();
    }
    printf("take()\n");
    return task;
}

void ThreadPool::add(Task task)
{
    MutexLockGuard Lock(_mutex);
    
    while(fulled())
    {
        _canAdd.wait();
    }
    _tasks.push_back(task);
    _canTake.notify();
    printf("add()\n");
}