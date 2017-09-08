#ifndef _MYTH52125_LOGGER_H_
#define _MYTH52125_LOGGER_H_

#include <codebase/base/StringArg.h>
#include <codebase/base/LogFile.h>
#include <iostream>
using namespace std;

namespace myth52125
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
	
	template<typename T>
	size_t formatNum(T v);
public:
	Logger& operator<<(int i);
	Logger& operator<<(unsigned int i);
	Logger& operator<<(short i);
	Logger& operator<<(unsigned short i);
	Logger& operator<<(long i);
	Logger& operator<<(unsigned long i);
	Logger& operator<<(void *i);
	Logger& operator<<(const char &i)
	{
		append(&i,1);
		return *this;
	}

	Logger& operator<<(const char* str)
	{
		if(str)
		{
			append(str,strlen(str));
		}else{
			append("NULL",4);
		}
		return *this;
	}

	Logger& operator<<(const unsigned char * str)
	{
		return operator<<(reinterpret_cast<const char*>(str));
	}

	Logger& operator<<(const StringArg &i)
	{
		append(i.c_str(),i.size());
		return *this;
	}

	Logger& operator<<(std::string &i)
	{
		append(i.c_str(),i.size());
		return *this;
	}
};







}



}



#endif
