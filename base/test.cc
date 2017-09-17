// #include <codebase/base/Debug.h>
// #include <codebase/base/MutexLock.h>
// #include <codebase/base/File.h>
// #include <codebase/base/LogStream.h>
// #include <codebase/base/StringArg.h>
// #include <codebase/base/LogStream.h>
// #include <codebase/base/Logger.h>
// #include <codebase/base/Timestamp.h>
// #include <codebase/base/EveryThread.h>
#include <codebase/base/ThreadPool.h>
#include <codebase/base/Thread.h>
#include <iostream>
#include <unistd.h>
#include <boost/bind.hpp>
#include <pthread.h>

using namespace myth52125;
using namespace myth52125::base::thread;
using namespace myth52125::base;

void* funs(void* arg)
{
	std::cout<<"start"<<std::endl;
	ThreadPool *p = (ThreadPool*)arg;
	p->start();
}

void fun()
{
	std::cout<<"one thread "<<std::endl;
}

void cb()
{
	std::cout<<"cb "<<std::endl;
}

int main()
{
// 	MutexLock l;
// 	MutexLock locl(l);

// //	::printf("stream head");
	
// 	for(int i =0;i<=10;i++)
// 	{
// 	LOG_TRACE<<"   pppppppppppppppp"<<"33124das00000000d\n";
// 	}
// 	Timestamp t;
	//LOG_TRACE<<t.toString();


	ThreadPool p(4,"haha");
	p.setCallBack(cb);
	pthread_t t;	
	pthread_create(&t,NULL,funs,(void *)&p);
	std::cout<<"create: "<<std::endl;
	while(true)
	{
		p.add(fun);
	
	}
	pthread_join(t,NULL);
	


	
	


}

//g++ -o test test.cc ../../codebase/base/Debug.h ../../codebase/base/Debug.h ../../codebase/base/EveryThread.h ../../codebase/base/File.h ../../codebase/base/File.cc ../../codebase/base/LogStream.h ../../codebase/base/LogStream.cc ../../codebase/base/Logger.h ../../codebase/base/Logger.cc ../../codebase/base/MutexLock.h ../../codebase/base/MutexLock.cc ../../codebase/base/StringArg.h -I../../ -lpthread

//g++ -o test test.cc  ../../codebase/base/MutexLock.h ../../codebase/base/File.h ../../codebase/base/File.cc ../../codebase/base/LogStream.h ../../codebase/base/LogStream.cc ../../codebase/base/EveryThread.cc ../../codebase/base/StringArg.h ../../codebase/base/Logger.h ../../codebase/base/Timestamp.h ../../codebase/base/Timestamp.cc ../../codebase/base/EveryThread.h -I../../ -std=c++11 -g
