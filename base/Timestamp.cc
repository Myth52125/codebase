#include <codebase/base/Timestamp.h>
#include <stdio.h>
#include <sys/time.h>
#include <iostream>
Timestamp::Timestamp()
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	int64_t sec = tv.tv_sec;
	std::cout<<" () "<<sec*mircoPerSecond+static_cast<int>(tv.tv_usec)<<std::endl;
	Timestamp(sec*mircoPerSecond+static_cast<int>(tv.tv_usec));

}


Timestamp::Timestamp(time_t t,int micro)
	:Timestamp(static_cast<int64_t>(t)+micro)
{
	std::cout<<"call me"<<std::endl;
}

std::string Timestamp::toString(bool showMirco)
{
	struct tm t;
	time_t second = _mircosecond / mircoPerSecond;
	gmtime_r(&second ,&t);

	char buf[32] = {0};
	if(showMirco)
	{
		int mirco = static_cast<int>(_mircosecond % mircoPerSecond);
		snprintf(buf,sizeof(buf),"%4d%02d%02d %02d:%02d:%02d.%06d",
				t.tm_year+1970,t.tm_mon+1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec,mirco);
	}else{
	
		snprintf(buf,sizeof(buf),"%4d%02d%02d %02d:%02d:%02d",
				t.tm_year+1970,t.tm_mon+1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec);
	
	}
	return std::string(buf);
}
