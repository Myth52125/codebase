#include <codebase/base/MutexLock.h>
#include <codebase/base/EveryThread.h>

#include <cassert>
using namespace myth52125;
using namespace myth52125::thread;
using namespace myth52125::base;


MutexLock::MutexLock()
    :m_threadtid(gettid())
{
    pthread_mutex_init(&m_mutex,NULL);
}
MutexLock::~MutexLock()
{
    pthread_mutex_destroy(&m_mutex);
}
void MutexLock::lock()
{
    pthread_mutex_lock(&m_mutex);
}
void MutexLock::unlock()
{
    //为沙assert(),可能存在不同线程解锁？    
    assert(m_threadtid == gettid());
    pthread_mutex_unlock(&m_mutex);
}
pthread_mutex_t *MutexLock::mutex()
{
    return &m_mutex;
}

MutexLockGuard::MutexLockGuard(MutexLock &mutex)
    :mq_mutex(mutex)
{
    mq_mutex.lock();
}
MutexLockGuard::~MutexLockGuard()
{
    mq_mutex.unlock();
}