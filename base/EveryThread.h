#ifndef _MYTH52125_EVERYTHREAD_H_
#define _MYTH52125_EVERYTHREAD_H_

#include <pthread.h>

namespace myth52125
{
namespace base
{

extern __thread pid_t _threadTid;
extern __thread char _threadName[32];

pid_t gettid();

}
}



#endif