#include <codebase/net/EventLoop.h>

#include <sys/eventfd.h>

#include <boost/bind.hpp>


using namespace myth52125;
using namespace myth52125::net;

int createEventFd()
{
	int fd = ::eventfd(0,EFD_NONBLOCK | EFD_CLOEXEC);
	return fd;
}



EventLoop::EventLoop()
	:_loop(false),_quit(false),_eventHanling(false),
	_wakeFd(createEventFd()),_wakeChannel(new Channel(this,_wakeFd)),
	_poller(new PollPoller(this))
{
	_wakeChannel->setReadCallback(
				boost::bind(&EventLoop::handleRead,this)
				);
	_wakeChannel->waitRead();
}



//only for _wakeFd and _wakeChannel
void EventLoop::handleRead()
{
	uint64_t result;
	size_t size = ::read(_wakeFd,&result,sizeof(result));
}

//only for _wakeFd and _wakeChannel , wakeup loop.
void EventLoop::wakeup()
{
	uint64_t result=1;
	size_t size = ::write(_wakeFd,&result,sizeof(result));
}


void EventLoop::loop()
{
	_loop = true;
	_quit =false;
	while(!_quit)
	{
		_channels.clear();
		
		_pollReturnTime = _poller(10000, &_channels);

		_eventHanling = true;
		for(ChannelList::iterator it = _channels.begin(),it != _channels.end(),it++)
		{
			_currentChannel = it;

			_currentChannel.handleEvent();
		}
		_currentChannel = NULL;
		_eventHanling =false;


	}

}


void EventLoop::quit()
{
	_quit = true;
	wakeup();
}



