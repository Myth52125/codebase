#ifndef _MYTH52125_THREADPOOL_H_
#define _MYTH52125_THREADPOOL_H_

#include <codebase/base/StringArg.h>
#include <boost/functional.hpp>
#include <codebase/base/Thread.h>
#include <codebase/base/Condition.h>
#include <boost/ptr_container/ptr_vector.hpp>
#include <codebase/base/MutexLock.h>
#include <deque>

namespace myth52125
{
namespace base
{


class ThreadPool
{
public:
    ThreadPool(size_t i=4,StringArg name=StringArg("no name"));
    ~ThreadPool(){}

    typedef boost::function<void ()> Task;
    typedef boost::ptr_vector<Thread> ThreadVecotr;
private:
    size_t _threadNum;
    size_t _maxTaskSize;
    StringArg _name;
    bool _started;
    bool _stoped;
    Condition _canAdd;
    Condition _canTake;
    MutexLock _mutex;
    Task _cb;
    ThreadVecotr _threads;
    std::deque<Task> _tasks;


    Task takeTask();
    void runInThread();
    bool fulled();

public:
    void add(Task task);
    void start();
    void stop();
    void setCallBack(Task task)
    {
        _cb=task;
    }
    void setMaxTask(size_t i);
};







}



}



#endif
