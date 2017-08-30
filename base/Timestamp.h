#ifndef _TIMESTAMP_H_M_
#define _TIMESTAMP_H_M_

#include <string>
#include <time.h>
#include <inttypes.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
namespace myth52125
{

class Timestamp
{
private:
	int64_t _mircosecond{0};
	int64_t now();
public:
	Timestamp();
	
	Timestamp(int64_t t)
		:_mircosecond(t)
	{
		std::cout<<"in construstor t: "<<&_mircosecond<<std::endl;
	}

	Timestamp(time_t ,int micro);

	bool vaild()
	{
		return _mircosecond>0;
	}

	static Timestamp invalid()
	{
		return Timestamp(0);
	}
	
		
	int64_t mircosecond()
	{
//		showbytes((unsigned char *)&_mircosecond,sizeof(_mircosecond));
		return _mircosecond;
	}


	void showbytes(unsigned char *buf ,int len)
	{
		for(int i = 0; i<len;i++)
		{
			std::cout<<""<<(int)buf[i]<<" ";
		}
		std::cout<<std::endl;
	}



	std::string toString(bool showMirco = true);


	static const int mircoPerSecond = 1000*1000;	
};


inline Timestamp addTime(Timestamp time,int t)
{
	return Timestamp(time.mircosecond() + t*Timestamp::mircoPerSecond);
}

inline bool  operator>(Timestamp &l,Timestamp &r)
{
	return l.mircosecond()	> r.mircosecond()	;
}

inline bool operator==(Timestamp &l,Timestamp &r)
{
	return l.mircosecond()	== r.mircosecond()	;
	
}
inline double timeDiffence(const Timestamp &h, const Timestamp &l)
{
	int64_t diffence = h.mircosecond() -l.mircosecond();
	return static_cast<double>(diffence/mircoPerSecond);



}

class TimeConsume
{
private:
	Timestamp _time;
public:
	TimeConsume()
		:_time(Timestamp())
	{}
	~TimeConsume()
	{
		status();
	}

	double status(bool print == true)
	{
		Timestamp now();
		double diffence = now.mircosecond() - _time.mircosecond();
		if(print)
		{
			std::cout<<"From the beginning to now after "<<diffence<<" seconds. "<<std::endl;
		}
		
		return diffence;
	}




};

}
#endif

