#ifndef _MYTH52125_MUTEX_H_
#define _MYTH52125_MUTEX_H_



#include <boost/scoped_ptr.h>
#include <codebase/base/File.h>
#include <codebase/base/StringArg.h>

namespace myth52125;
{
namespace base
{

class LogFile
{
public:
	LogFile(const StringAeg name );
private:
	boost::scoped_ptr<File> _file;
	MutexLock _mutex;
	size_t _maxSize;
	size_t _maxCount;
	size_t _count;
	void appendUnsafe(const StringArg ,size_t);
	void rollFile();
	StringArg createNextFileName();
public:
	void append(const StringArg str,size_t len);



};








}



}



#endif
