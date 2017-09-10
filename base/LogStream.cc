
#include <codebase/base/File.h>
#include <codebase/base/LogStream.h>

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
		tmp = static_cast<int>(value % radix);
		value/=radix;
		*p = digits[tmp+9]; 
		
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


#include <iostream>
using namespace std;
#include <string>

void LogStream::append(const StringArg str ,size_t len)
{
	if((TMPBUFSIZE-_bufWritten) > len)
	{
	
		memcpy(_buf+_bufWritten ,str.c_str(),len);
		_bufWritten += len;
	}
}


void LogStream::printf()
{
	::printf(_buf,_bufWritten);
	_bufWritten = 0;
	bzero(_buf,sizeof(_buf));
}

template<typename T>
size_t LogStream::formatNum(T v)
{
	char p[32];
	size_t len = numToString(p,v);
	append(p,len);

}


LogStream& LogStream::operator<<(long i)
{
	formatNum(i);
	return *this;
}
LogStream& LogStream::operator<<(unsigned long i )
{
	formatNum(i);
	return *this;
}
LogStream& LogStream::operator<<(int i)
{
	formatNum(i);
	return *this;

}
LogStream& LogStream::operator<<(unsigned int i)
{
	formatNum(i);
	return *this;

}
LogStream& LogStream::operator<<(short i)
{
	formatNum(i);
	return *this;

}
LogStream& LogStream::operator<<(unsigned short i)
{
	formatNum(i);
	return *this;

}

LogStream& LogStream::operator<<(void *i)
{

}