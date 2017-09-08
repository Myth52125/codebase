
#include <codebase/base/File.h>
#include <codebase/base/LogFile.h>

#include <algorithm>

#include <iostream>
using namespace std;



namespace myth52125
{
namespace tools
{

const char digits[]="98765432101234567890ABCDEF";
template<typename T>

size_t numToString(char buf[],T value,int radix = 10)
{
	int tmp;
	char *p=buf;
	do
	{
		tmp = static_cast<int>(value%radix);
		value/=radix;
		*p = digits[tmp]; 
		p++;
	}while( value != 0);

	if(radix < 0)
	{
		*p='-';
		p++;
	}
	*p='\0';
	std::reverse(buf,p);
	return 	p-buf;
}
}
}

using namespace myth52125;
using namespace myth52125::base;
using namespace myth52125::tools;




LogFile::LogFile(const StringArg name,size_t maxSize,size_t maxCount)
	:_file(new File(name)),_maxSize(maxSize),_maxCount(maxCount),
	_mutex(NULL),_baseName(name),_bufWritten(0)
{

}

void LogFile::tmpAppend(const StringArg str ,size_t len)
{
	if((TMPBUFSIZE-_bufWritten) > len)
	{
		memcpy(_buf+_bufWritten ,str.c_str(),len);
		_bufWritten += len;
	}
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

void LogFile::writeInToFile()
{
	append(_buf,_bufWritten);
	
	_bufWritten = 0;
}


template<typename T>
size_t LogFile::formatNum(T v)
{
	char p[32];
	size_t len = numToString(p,v);
	tmpAppend(p,v);

}


LogFile& LogFile::operator<<(long i)
{
	formatNum(i);
	return *this;
}
LogFile& LogFile::operator<<(unsigned long i )
{
	formatNum(i);
	return *this;
}
LogFile& LogFile::operator<<(int i)
{
	formatNum(i);
	return *this;

}
LogFile& LogFile::operator<<(unsigned int i)
{
	formatNum(i);
	return *this;

}
LogFile& LogFile::operator<<(short i)
{
	formatNum(i);
	return *this;

}
LogFile& LogFile::operator<<(unsigned short i)
{
	formatNum(i);
	return *this;

}

LogFile& LogFile::operator<<(void *i)
{

}