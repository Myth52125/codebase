#ifndef _MYTH52125_CONDITION_H_
#define _MYTH52125_CONDITION_H_

#include <codebase/base/MutexLock.h>
#include <codebase/base/StringArg.h>
#include <pthread.h>

#include <iostream>
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
        std::cout<<"mutex :"<<_mutex.mutex()<<std::endl;
        int result = pthread_cond_init(&_cond,NULL);
        NOTZEROERR(result,"condition init error");
    }

    ~Condition()
    {
        int result= pthread_cond_destroy(&_cond);
        NOTZEROERR(result,"condition destroy error");
        
    }
private:
    pthread_cond_t _cond;
    MutexLock &_mutex;
public:
    void wait()
    {
        int result= pthread_cond_wait(&_cond,_mutex.mutex());
        NOTZEROERR(result,"condition wait error");
        
    }
    void notify()
    {
        int result= pthread_cond_signal(&_cond);
        NOTZEROERR(result,"condition notify error");
        
    }
    void notifyAll()
    {
        int result=pthread_cond_broadcast(&_cond);
        NOTZEROERR(result,"condition notifyAll error");
    }


};







}



}



#endif
