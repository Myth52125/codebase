#ifndef _CONDITION_H_M_
#define _CONDITION_H_M_



#include <pthread.h>

namespace myth52125
{

class Condition
{
private:
	pthread_cond_t con;
	MutexLock &_mutex;
public:
	Condition(MutexLock &mutex)
		:_mutex(mutex)
	{
		int result = pthread_cond_init(&con,NULL);
	}

	~condition()
	{
		int result =  pthread_cond_destroy(&cond);
	}
		

	void wait()
	{
		int result = pthread_cond_wait(&con,&_mutex);	
	}
	void wakeup()
	{
		int result = pthread_cond_signal(&con);
	
	}

	void wakeupAll()
	{
		int result = pthread_cond_broadcast(&con);	
	}
};













}





#endif
