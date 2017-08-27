
#include <codebase/base/FileTool.h>

using namespace myth52125;

FileAppend::FileAppend(const std::string &fileName)
	:_fp(::fopen(fileName.c_str(),"ae")),
	_writtenBytes(0)
{
	::setbuffer(_fp,_buffer,sizeof(_buffer));

}


size_t FileAppend::write(const char *logLine, size_t len)
{
	return ::fwrite_unlocked(logLine, 1, len, _fp);
}

void FileAppend::append(const char *logLine ,size_t len)
{
	size_t hasWrite = write(logLine, len);
	size_t remain = len - hasWrite;
	while (remain > 0 )
	{
		size_t writeAgain = write(logLine + hasWrite , remain);					
		if(writeAgain == 0)
		{
			
		
		}

		hasWrite += writeAgain;
		remain = len =hasWrite;
	}
	_writtenBytes += len;
}

void FileAppend::append(const std::string &logLine)
{
	append(logLine.c_str(), logLine.size());

}

void FileAppend::flush()
{
	::fflush(_fp);
}
