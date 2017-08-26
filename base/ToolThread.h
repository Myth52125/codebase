#ifndef _TOOLTHREAD_H_M_
#define _TOOLTHREAD_H_M_

#include <iostream>
#include <pthread.h>
#include <sys/syscall.h> //for SYS_gettidd
#include <unistd.h>		//for syscall()

namespace myth52125
{
namespace ToolThread
{


//__thread pid_t t_threadTid;
//thread_local std::string t_threadName;

inline pid_t tid()
{
	return static_cast<pid_t>(syscall(SYS_gettid));
}


}
}


#endif
