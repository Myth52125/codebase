#ifndef _MYTH52125_MUTEXLOCK_H_
#define _MYTH52125_MUTEXLOCK_H_

#include <pthread.h>

#include <codebase/base/EveryThread.h>

namespace myth52125
{
namespace base
{

class MutexLock
{
public:
    MutexLock();
    ~MutexLock();
private:
    pid_t _threadtid;
    pthread_mutex_t _mutex;
public:
    void lock();
    void unlock();
    pthread_mutex_t *mutex();
};

//RAII锁
class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock &);
    ~MutexLockGuard();
private:
    MutexLock &_mutex;
};
}
}



#endif