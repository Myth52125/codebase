#include <codebase/base/LogStream.h>
#include <stdlib.h>
#include <iostream>

using namespace myth52125;

LogStream &LogStream::operator<<(int v)
{
	return *this;
}


LogStream &LogStream::operator<<(unsigned v)
{
	return *this;
}


LogStream &LogStream::operator<<(short v)
{
	return *this;
}

LogStream &LogStream::operator<<(double v)
{
	return *this;
}
LogStream &LogStream::operator<<(long long v)
{
	return *this;
}
LogStream &LogStream::operator<<(const char *v)
{
	append(v ,1);
	return *this;
}
LogStream &LogStream::operator<<(std::string &v)
{
	append(v.c_str(),v.size());
	return *this;

}

