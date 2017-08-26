
#include <codebase/base/Thread.h>
#include <sys/prctl.h>

namespace myth52125
{
namespace assistant
{
class ThreadData
{
public:
	typedef myth52125::Thread::ThreadFunc ThreadFunc;
private:
	

public:
	std::string _threadName;
	ThreadFunc _func;




	ThreadData(const ThreadFunc &func, const std::string &threadName = "myth52125 annoymous thread")
		:_func(func), _threadName(threadName)
	{
		
	}

	void runInThread()
	{
//		ToolThread::t_threadName = _threadName;
		::prctl(PR_SET_NAME, _threadName);
		
		_func();

	}
};


void *startInThread(void *arg)
{
	ThreadData *data = static_cast<ThreadData *>(arg);
	data->runInThread();

	return NULL;
}

}
}

using namespace myth52125;

Thread:: Thread(const ThreadFunc &func, const std::string &name)
	:_func(func),_threadName(name),_isStarted(false),_isJoined(false),_tid(ToolThread::tid()),
	_threadId(0)
{

}

Thread::~Thread()
{
	if(_isStarted && !_isJoined )
	{
		pthread_detach(_threadId);
	}
}


void Thread::start()
{
	if(!_isStarted)
	{

		assistant::ThreadData *data=new assistant::ThreadData(_func,_threadName);

		int result = pthread_create(&_threadId,NULL,assistant::startInThread,&data);
		_isStarted = true;
	}
}


void Thread::join()
{
	if(!_isJoined)
	{
		int result = pthread_join(_threadId,NULL);
		_isJoined = true;
	
	}

}
