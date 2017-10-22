#include <codebase/base/EveryThread.h>

#include <sys/syscall.h> //SYS_gettid
#include <unistd.h>      //syscall()

namespace myth52125
{
namespace thread
{

__thread pid_t g_thread_tid=-1;
__thread  char g_thread_name[32]="None";

//syscall系统调用获取线程的tid
pid_t gettid()
{
    return static_cast<pid_t>(::syscall(SYS_gettid));
}

}
}