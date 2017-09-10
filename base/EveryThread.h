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


extern __thread  pid_t _threadTid;
extern __thread  char _threadName[32];
extern __thread  size_t _threadNameLen;	

extern  pid_t getTid();





}






}
}






#endif
