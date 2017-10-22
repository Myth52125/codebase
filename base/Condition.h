#ifndef MYTH52125_CONDITION_H

#define MYTH52125_CONDITION_H



#include <pthread.h>
#include <codebase/base/MutexLock.h>

namespace myth52125
{


class Condition
{
public:
    explicit Condition(MutexLock &mutex)
    :mq_mutex(mutex)
    {
        pthread_cond_init(&m_cond);
    }
    ~Condition()
    {
        pthread_cond_destroy(&m_cond);
    }

private:
    MutexLock &mq_mutex;
    pthread_cond_t m_cond;

public:
    void wait()
    {
        pthread_cond_wait(&m_cond,mq_mutex.mutex());
    }
    void notify()
    {
        pthread_cond_signal(&m_cond);
    }
    void notifyAll()
    {
        pthread_cond_broadcast(&m_cond);
    }
};

}

#endif  //MYTH52125_CONDITION_H 