
#include <codebase/base/File.h>
#include <codebase/base/Debug.h>
#include <codebase/base/EveryThread.h>
#include <sys/syscall.h>
#include <unistd.h>


namespace myth52125
{
namespace base
{
namespace thread
{
	__thread  pid_t _threadTid = 0;
	__thread  char _threadName[32]= "unknow";
	__thread  size_t _threadNameLen = 6;	
	
	
	 pid_t getTid()
	{
	
		//return _threadTid;
		return static_cast<pid_t>(::syscall(SYS_gettid));
		// _threadTid =  static_cast<pid_t>(::syscall(SYS_gettid));
		// return _threadTid;
	}

}
}
}

