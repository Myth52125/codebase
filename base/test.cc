#include <codebase/base/Debug.h>
#include <codebase/base/MutexLock.h>
#include <codebase/base/File.h>
#include <codebase/base/LogFile.h>
#include <codebase/base/Logger.h>
#include <codebase/base/StringArg.h>

using namespace myth52125;
using namespace myth52125::base::thread;
using namespace myth52125::tools;
using namespace myth52125::base;

int main()
{
	Logger("log.txt",1000,10);



}

//g++ -o test test.cc ../../codebase/base/Debug.h ../../codebase/base/Debug.h ../../codebase/base/EveryThread.h ../../codebase/base/File.h ../../codebase/base/File.cc ../../codebase/base/LogFile.h ../../codebase/base/LogFile.cc ../../codebase/base/Logger.h ../../codebase/base/Logger.cc ../../codebase/base/MutexLock.h ../../codebase/base/MutexLock.cc ../../codebase/base/StringArg.h -I../../ -lpthread

