#include <codebase/base/MutexLock.h>
#include <codebase/base/EveryThread.h>

#include <cassert>
using namespace myth52125;
using namespace myth52125::base;

MutexLock::MutexLock()
    :_threadtid(gettid())
{
    pthread_mutex_init(&_mutex,NULL);
}
MutexLock::~MutexLock()
{
    pthread_mutex_destroy(&_mutex);
}
void MutexLock::lock()
{
    pthread_mutex_lock(&_mutex);
}
void MutexLock::unlock()
{
    //为沙assert(),可能存在不同线程解锁？    
    assert(_threadtid == gettid());
    pthread_mutex_unlock(&_mutex);
}

MutexLockGuard::MutexLockGuard(MutexLock &mutex)
    :_mutex(mutex)
{
    _mutex.lock();
}
MutexLockGuard::~MutexLockGuard()
{
    _mutex.unlock();
}