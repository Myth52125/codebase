#ifndef _TIMESTAMP_H_M_
#define _TIMESTAMP_H_M_

#include <string>
#include <time.h>
#include <inttypes.h>
#include <iostream>
class Timestamp
{
private:
	int64_t _mircosecond;

public:
	Timestamp();
	
	Timestamp(int64_t t)
		:_mircosecond(t)
	{
//		_mircosecond = t;
		std::cout<<"in construstor t: "<<t<<" "<<_mircosecond<<std::endl;
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
		
		return _mircosecond;
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

#endif
