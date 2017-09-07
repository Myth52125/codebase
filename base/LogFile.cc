
#include <codebase/base/File.h>
#include <codebase/base/LogFile.h>

using namespace myth52125;
using namespace myth52125::base;




LogFile::LogFile(const StringArg name,size_t maxSize,size_t maxCount)
	:_file(new File(name)),_maxSize(maxSize),_maxCount(maxCount),
	_mutex(NULL),_baseName(name)
{

}



void LogFile::append(const StringArg str,size_t len)
{
	if(_mutex)
	{
		MutexLockGuard look(*_mutex);
		appendUnsafe(str,len);
	}else{
		appendUnsafe(str,len);
	}
}

void LogFile::appendUnsafe(const StringArg str ,size_t len)
{
	_file->append(str.c_str(),len);
	_count ++;
	if(_file->written() > _maxSize || _count > _maxCount)
	{
		rollFile();
		_count = 0;	
	}
}

void LogFile::rollFile()
{
	StringArg nextFile = createNextFileName(_baseName);
	_file.reset(new File(nextFile));

}
StringArg LogFile::createNextFileName(const StringArg &str)
{
	//写完timeStamp 再来写
	return StringArg("newLog");

}



