#ifndef _MYTH52125_STRINGARG_H_
#define _MYTH52125_STRINGARG_H_

#include <string.h>
#include <string>
#include <utility>

namespace myth52125
{
namespace base
{


class StringArg
{
public:
	StringArg()
		:_data(new char[1])
	{
		*_data = '\0';
	}
	~StringArg()
	{
		delete[] _data;
	}

	StringArg(const char *str)
		:_data(new char[strlen(str)+1])
	{
		strcpy(_data,str);
	}

	StringArg(const StringArg &rhs)
		:_data(new char[rhs.size()+1])
	{
		strcpy(_data,rhs.c_str());
	}
	
	StringArg(const std::string &str)
		:_data(new char[str.size()+1])
	{
		strcpy(_data,str.c_str());
	}

//	StringArg(StringArg&& rhs)
//		:_data(rhs._data)
//	{
//		rhs._data = nullptr;
//	}

	StringArg &operator=(StringArg rhs)
	{
		swap(rhs);
		return *this;
	}

private:
	char *_data;

public:
	size_t size() const
	{
		return strlen(_data);
	}

	const char *c_str() const
	{
		return _data;
	}
	void swap(StringArg &rhs)
	{
		std::swap(_data,rhs._data);
	}

};

}
}













#endif
