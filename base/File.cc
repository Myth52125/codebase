
#include <codebase/base/File.h>
#include <codebase/base/Debug.h>

#include <fcntl.h>
#include <stdio.h>

using namespace myth52125;
using namespace myth52125::base;

File::File(const StringArg path)
	:_fp(::fopen(path.c_str(),"ae")),_written(0)
{
	NULLERR(_fp,"open file stream");
	::setvbuf(_fp,_buffer,_IOFBF,64*1024);
}

File::~File()
{
	::fclose(_fp);
}

int File::write(const char *str,size_t len)
{
	return ::fwrite_unlocked(str,1,len,_fp);

}

void File::append(const char *str,size_t len)
{
	size_t written = write(str,len);
	size_t remain = len -written;

	while(remain > 0)
	{
		size_t n = write(str+written,remain);

		if(n ==0)
		{

		}
		remain -= n;
		written +=n;
	}
	_written+=len;
}

void File::flush()
{
	::fflush(_fp);
}
