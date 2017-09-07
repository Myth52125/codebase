#ifndef _MYTH52125_LOGFILE_H_
#define _MYTH52125_LOGFILE_H_



#include <boost/scoped_ptr.hpp>
#include <codebase/base/File.h>
#include <codebase/base/StringArg.h>
#include <codebase/base/MutexLock.h>
namespace myth52125
{
namespace base
{

class LogFile
{
public:
	LogFile(const StringArg name,size_t _maxSize,size_t maxCount );
private:
	boost::scoped_ptr<File> _file;
	boost::scoped_ptr<MutexLock> _mutex;
	size_t _maxSize;
	size_t _maxCount;
	size_t _count;
	void appendUnsafe(const StringArg ,size_t);
	void rollFile();
	StringArg _baseName;
	StringArg createNextFileName(const StringArg &str);
public:
	void append(const StringArg str,size_t len);



};








}



}



#endif
