
#include <codebase/net/PollPoller.h>
#include <poll.h>
#include <codebase/net/Channel.h>

using namespace myth52125;
using namespace myth52125::net;


Timestamp PollPoller::poller(int timeout, ChannelList * channels)
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
	for (PollFdList::iterator it = _pollFdList.begin() ;
			it != _pollFdList.end() && num >0;
			++it
			)
	{
		if(it -> revents > 0)
		{
			num--;
			ChannelMap::iterator cm = _channels.find(it->fd);

			Channel *channel = cm->second;	

			channel->revents(it->revents);

			channels->push_back(channel);
		}
	
	}


}



void PollPoller::updateChannel(Channel *channel)
{
	if(channel->index() == -1)
	{
		struct 	pollfd pfd ;
		pfd.fd = channel->fd();
		pfd.events = channel ->events();
		pfd.revents = 0;
		int index = static_cast<int>(_channels.size() - 1);
		channel->index(index);
		_pollFdList.push_back(pfd);
		_channels[channel->fd()]=channel;
	}else{
		int index = channel->index();
		struct pollfd &pfd = _pollFdList[index];
		pfd.fd = channel->fd();
		pfd.events = channel->events();
		pfd.revents = 0;
	
	
	}


}


void PollPoller::removeChannel(Channel *channel)
{
	int index = channel -> index();
	const struct pollfd &pfd = _pollFdList[index];
	int result = _channels.erase(channel->fd());
	
	if(static_cast<int>(_pollFdList.size()-1 == index))
	{
		_pollFdList.pop_back();
	}else{
		int end = _pollFdList.back().fd;

		iter_swap(_pollFdList.begin()+index , _pollFdList.end()-1);

		_channels[end]->index(index);
		_pollFdList.pop_back();
	}

}

