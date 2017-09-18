#ifndef _MYTH52125_MUTEXLOCK_H_
#define _MYTH52125_MUTEXLOCK_H_

#include <codebase/base/StringArg.h>
#include <codebase/base/EveryThread.h>
#include <codebase/base/Debug.h>
#include <iostream>
namespace myth52125
{
namespace base
{

using namespace myth52125::base::thread;

class MutexLock
{
public:
	MutexLock()
		:_mutexPid(getTid())
	{
		int result = pthread_mutex_init(&_mutex,NULL);
		NOTZEROERR(result,"mutex init error");
	}
	~MutexLock()
	{
		int result = pthread_mutex_destroy(&_mutex);
		NOTZEROERR(result ,"mutex destroy error")
	}
private:
	pthread_mutex_t _mutex;
	pid_t _mutexPid;
public:
	void lock()	
	{	
		
		int result = pthread_mutex_lock(&_mutex);
		NOTZEROERR(result , "mutex lock err");
		
	}
	void unlock()
	{
		int result = pthread_mutex_unlock(&_mutex);
		NOTZEROERR(result , "mutex unlock err");
		
	}


	pthread_mutex_t *mutex()
	{
		return &_mutex;
	}


};


class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock &mutex)
		:_mutex(mutex)
	{
		_mutex.lock();
	}
	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	MutexLock &_mutex;
public:

};






}



}



#endif
