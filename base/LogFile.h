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
	void append(const StringArg str,size_t len);

	template<typename T>
	size_t formatNum(T v);
public:
	LogFile& operator<<(int i);
	LogFile& operator<<(unsigned int i);
	LogFile& operator<<(short i);
	LogFile& operator<<(unsigned short i);
	LogFile& operator<<(long i);
	LogFile& operator<<(unsigned long i);
	LogFile& operator<<(void *i);
	LogFile& operator<<(const char &i)
	{
		append(&i,1);
		return *this;
	}

	LogFile& operator<<(const char* str)
	{
		if(str)
		{
			append(str,strlen(str));
		}else{
			append("NULL",4);
		}
		return *this;
	}

	LogFile& operator<<(const unsigned char * str)
	{
		return operator<<(reinterpret_cast<const char*>(str));
	}

	LogFile& operator<<(const StringArg &i)
	{
		append(i.c_str(),i.size());
		return *this;
	}

	LogFile& operator<<(std::string &i)
	{
		append(i.c_str(),i.size());
		return *this;
	}


};








}



}



#endif
