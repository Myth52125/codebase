#ifndef _MYTH52125_LOGSTREAM_H_
#define _MYTH52125_LOGSTREAM_H_



#include <boost/scoped_ptr.hpp>
#include <codebase/base/File.h>
#include <codebase/base/StringArg.h>
#include <codebase/base/MutexLock.h>
namespace myth52125
{
namespace base
{

#define TMPBUFSIZE 128

class LogStream
{
public:
	LogStream()
		:_bufWritten(0)
	{}
private:
	char _buf[TMPBUFSIZE];
	size_t _bufWritten;
	void append(const StringArg str,size_t len);

	template<typename T>
	size_t formatNum(T v);
public:
	void printf();

	LogStream& operator<<(int i);
	LogStream& operator<<(unsigned int i);
	LogStream& operator<<(short i);
	LogStream& operator<<(unsigned short i);
	LogStream& operator<<(long i);
	LogStream& operator<<(unsigned long i);
	LogStream& operator<<(void *i);
	LogStream& operator<<(const char &i)
	{
		append(&i,1);
		return *this;
	}

	LogStream& operator<<(const char* str)
	{
		if(str)
		{
			append(str,strlen(str));
		}else{
			append("NULL",4);
		}
		return *this;
	}

	LogStream& operator<<(const unsigned char * str)
	{
		return operator<<(reinterpret_cast<const char*>(str));
	}

	LogStream& operator<<(const StringArg &i)
	{
		append(i.c_str(),i.size());
		return *this;
	}

	LogStream& operator<<(std::string &i)
	{
		append(i.c_str(),i.size());
		return *this;
	}


};








}



}



#endif
