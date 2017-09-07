#ifndef _MYTH52125_MUTEX_H_
#define _MYTH52125_MUTEX_H_
#include <codebase/base/StringArg.h>
#include <codebase/base/LogFile.h>
namespace myth52125;
{
namespace base
{


class Logger
{
public:	
	Logger(const StringArg name,size_t maxSize,size_t maxCount);
private:
	LogFile _file;
	void append(const StringArg str,size_t len);
public:
	

};







}



}



#endif
