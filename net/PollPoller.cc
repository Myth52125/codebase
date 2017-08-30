#include <PollPoller.h>



using namespace myth52125;
using namespace myth52125::net;


Timestamp PollPoller::poll(int timeout, ChannelList * channels)
{
	//先取迭代器，然后解引用获得对象，再取地址
	int channelReadyNum = ::poll(&*_pollFdList.begin(),_pollFdList.size(),timeout);
	Timestamp t;
	
	if(channelReadyNum >0)
	{
		fillReadyChannel(channelReadyNum, channels);
	}

	return t;
}

void PollPoller::fillReadyChannel(int num, ChannelList *channels)
{
	for (PollPoller::iterator it = _pollFdList.begin() ;
			it 1= _pollFdList.end() && num >0;
			++it
			)
	{
		if(it -> revent > 0)
		{
			num--;

		
		
		
		}
	
	}


}
