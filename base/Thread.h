#ifndef _THREAD_H_M_
#define _THREAD_H_M_

#include <pthread.h>

#include <boost/function.hpp>


#include <codebase/base/Mutex.h>
#include <codebase/base/ToolThread.h>


class Thread
{
public:
	typedef boost::function<void ()> ThreadFunc;
private:
	pthread_t 			_threadId;
	std::string			_threadName;
	bool 				_isStarted;
	bool				_isJoined;
	ThreadFunc 			_func;
	pid_t				_tid;
	
public:
	explicit Thread(const ThreadFunc &func, const std::string &name = "");
	~Thread();
	
	void start();
	void join();
	const pid_t tid();
	const std::string name();


};








#endif
