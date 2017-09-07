
#include <codebase/base/Logger.h>

#include <codebase/base/Debug.h>

using namespace myth52125;
using namespace myth52125::base;


Logger::Logger(const StringArg name,size_t maxSize,size_t maxCount)
	:_file(LogFile(name,maxSize,maxCount))
{}
