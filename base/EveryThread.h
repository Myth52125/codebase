#ifndef _MYTH52125_EVERYTHREAD_H_
#define _MYTH52125_EVERYTHREAD_H_

#include <codebase/base/StringArg.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>

namespace myth52125
{
namespace base
{
namespace thread
{

__thread pid_t threadTid;
__thread char threadName[32];
__thread size_t threadNameLen = 0;




pid_t getTid()
{
	threadTid = static_cast<pid_t>(::syscall(SYS_gettid));
	return threadTid;
}





};






}
}






#endif
