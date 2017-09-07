
#include <codebase/base/Logger.h>

#include <codebase/base/Debug.h>

#include <algorithm>

namespace myth52125
{
namespace tools
{

const char digits[]="01234567890ABCDEF";
template<typename T>

size_t numToString(char buf[],T value,int radix = 10)
{
	int tmp;
	char *p=buf;
	do
	{
		p = static_cast<int>(value%radix);
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

template<typename T>
size_t Logger::formatNum(T v)
{
	char p[32];
	size_t len = numToString(p,v);
	append(p,v);

}



Logger::Logger(const StringArg name,size_t maxSize,size_t maxCount)
	:_file(LogFile(name,maxSize,maxCount))
{

}

void Logger::append(const StringArg str,size_t len)
{
	_file.append(str,len);
}


Logger& Logger::operator<<(long i)
{
	formatNum(i);
	return *this;
}
Logger& Logger::operator<<(unsigned long i )
{
	formatNum(i);
	return *this;
}
Logger& Logger::operator<<(int i)
{
	formatNum(i);
	return *this;

}
Logger& Logger::operator<<(unsigned int i)
{
	formatNum(i);
	return *this;

}
Logger& Logger::operator<<(short i)
{
	formatNum(i);
	return *this;

}
Logger& Logger::operator<<(unsigned short i)
{
	formatNum(i);
	return *this;

}

Logger& Logger::operator<<(void *i)
{

}
