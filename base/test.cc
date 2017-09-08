#include <codebase/base/Debug.h>
#include <codebase/base/MutexLock.h>
#include <codebase/base/File.h>
#include <codebase/base/LogFile.h>
#include <codebase/base/StringArg.h>
#include <codebase/base/LogFile.h>
#include <codebase/base/Logger.h>


using namespace myth52125;
using namespace myth52125::base::thread;
using namespace myth52125::base;

int main()
{
	MutexLock l;
	MutexLock locl(l);

	
	for(int i=0;i<10;i++)
	{
		LOG_TRACE<<i<<"   pppppppppppppppp"<<"33124dasd\n";
	
	}

}

//g++ -o test test.cc ../../codebase/base/Debug.h ../../codebase/base/Debug.h ../../codebase/base/EveryThread.h ../../codebase/base/File.h ../../codebase/base/File.cc ../../codebase/base/LogFile.h ../../codebase/base/LogFile.cc ../../codebase/base/Logger.h ../../codebase/base/Logger.cc ../../codebase/base/MutexLock.h ../../codebase/base/MutexLock.cc ../../codebase/base/StringArg.h -I../../ -lpthread

