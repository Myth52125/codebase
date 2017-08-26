
#ifndef _TOOLFUNC_H_M_
#define _TOOLFUNC_H_M_

#include <iostream>
#include <string>

namespace myth52125
{




inline void  notZeroErr(int i,const std::string &errmsg)
{
	if(i != 0)
	{
		std::cout<<"err in file :"<<__FILE__<<" line : "<<__LINE__<<" function :  "
			<<__func__<<", msg : "<<errmsg<<std::endl;

	}

}















}















#endif
