#ifndef _MYTH52125_CONDITION_H_
#define _MYTH52125_CONDITION_H_

#include <codebase/base/MutexLock.h>
#include <codebase/base/StringArg.h>
#include <pthread.h>

namespace myth52125
{
namespace base
{


class Condition
{
public:
    Condition(MutexLock &mutex)
    :_mutex(mutex)
    {
        pthread_cond_init(&_cond,NULL);
    }

    ~Condition()
    {
        pthread_cond_destroy(&_cond);
    }
private:
    pthread_cond_t _cond;
    MutexLock _mutex;
public:
    void wait()
    {
        pthread_cond_wait(&_cond,_mutex.mutex());
    }
    void notify()
    {
        pthread_cond_signal(&_cond);
    }
    void notifyAll()
    {
        pthread_cond_broadcast(&_cond); 
    }


};







}



}



#endif
