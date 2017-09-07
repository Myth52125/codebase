#ifndef _MYTH52125_FILE_H_
#define _MYTH52125_FILE_H_



#include <codebase/base/StringArg.h>


namespace myth52125
{
namespace base
{

class File
{
public:
	File(const StringArg path);
	~File();
private:
	char _buffer[64*1024];
	size_t _written;
	FILE* _fp;

	int write(const char* ,size_t );
public:
	void append(const char *,size_t);
	void flush();
	size_t written() {return _written;}
};










}



}



#endif
