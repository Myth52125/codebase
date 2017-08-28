#ifndef _LOGSTREAM_H_M_
#define _LOGSTREAM_H_M_

#include <string>
#include <string.h>
#include <iostream>

#define LOGBUFFERSIZE 64*1024

namespace myth52125
{


class LogBuffer
{
private:
	char _container[LOGBUFFERSIZE];
	char *_p;
public:
	LogBuffer()
		:_p(_container)
	{}

	void append(const char *buf, size_t len)
	{
		if(avail() > len)
		{
			memcpy(_p,buf,len);
			_p+=len;
		}
	}
	
	void append(const std::string &buf)
	{
		append(buf.c_str(),buf.size());
	}
	char *current()
	{
		return _p;
	}
	size_t size()
	{
		return static_cast<size_t>(_p - _container);
	}

	size_t avail()
	{
		return static_cast<size_t>( _container + sizeof(_container) - _p);
	}
	void reset()
	{
		_p = _container;
	}
	void bzero()
	{
		::bzero(_container , sizeof(_container));
	}

	const std::string toString()
	{
		return std::string(_container);
	}
	const char *buffer()
	{
		return _container;
	}
	void print()
	{
		std::cout<<"Buffer : "<<_container<<std::endl;
	}
};


class LogStream
{
private:
	LogBuffer _buffer;
public:
	LogStream &operator<<(int);
	LogStream &operator<<(unsigned int);
	LogStream &operator<<(short);
	LogStream &operator<<(double);
	LogStream &operator<<(long long);
	LogStream &operator<<(const char *);
	LogStream &operator<<(std::string&);



	void append(const char *data,size_t len)
	{
		_buffer.append(data,len);	
	}
	void print()
	{
		_buffer.print();
	}
};	


}







#endif
