#include <codebase/base/EveryThread.h>

#include <sys/syscall.h> //SYS_gettid
#include <unistd.h>      //syscall()

namespace myth52125
{
namespace base
{

__thread pid_t _threadTid=-1;
__thread  char _threadName[32]="None";


//syscall系统调用获取线程的tid
pid_t gettid()
{
    return static_cast<pid_t>(::syscall(SYS_gettid));
}

}
}