#ifndef _FILETOOL_H_M_
#define _FILETOOL_H_M_


#include <string>
#include <stdio.h>

namespace myth52125
{

class FileAppend
{
private:
	char _buffer[64*1024];
	FILE *_fp;
	size_t _writtenBytes;

	size_t write(const char *logLine, size_t len);
public:
	FileAppend(const std::string &fileName);
	~FileAppend()
	{
		::fclose(_fp);
	}

	void append(const char *logLine ,size_t len);
	void append(const std::string  &logLine);
	void flush();
	const size_t written();

};

}




#endif
