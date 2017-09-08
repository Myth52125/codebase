#include <codebase/base/Debug.h>
#include <codebase/base/MutexLock.h>
#include <codebase/base/File.h>
#include <codebase/base/LogFile.h>
#include <codebase/base/StringArg.h>

using namespace myth52125;
using namespace myth52125::base::thread;
using namespace myth52125::base;

int main()
{
	MutexLock l;
	MutexLock locl(l);
	File f("log.txt");
	f.append("asdasdads",9);
	
	LogFile log("logfile.txt",1000,100);


	log<<"12"<<1<<"asdasdasdasd\n";

}

//g++ -o test test.cc ../../codebase/base/Debug.h ../../codebase/base/Debug.h ../../codebase/base/EveryThread.h ../../codebase/base/File.h ../../codebase/base/File.cc ../../codebase/base/LogFile.h ../../codebase/base/LogFile.cc ../../codebase/base/Logger.h ../../codebase/base/Logger.cc ../../codebase/base/MutexLock.h ../../codebase/base/MutexLock.cc ../../codebase/base/StringArg.h -I../../ -lpthread

