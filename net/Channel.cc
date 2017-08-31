#include <codebase/net/Channel.h>

using namespace myth52125;
using namespace myth52125::net;

Channel::Channel(EventLoop *loop, int fd)
	:_loop(loop),_fd(fd),
	_events(0),_revents(0),
	_eventHandling(false),_addedToLoop(false),
	_index(-1)
{}


Channel::~Channel()
{}

void Channel::update()
{
	_addedToLoop=true;	//after update,loop hold this channel
	_loop->updateChannel(this);
}

void Channel::handleEvent(Timestamp when)
{	
	_eventHandling =true;
	if( (_revents & POLLHUP) && !(_revents & POLLIN))
	{
		if(_cl)
		{
			_cl();
		}
	}

	if( _revents & (POLLERR | POLLNVAL))
	{
		if(_er)
		{
			_er();
		}
	}

	if(_revents & ( POLLIN | POLLPRI | 	POLLRDHUP))
	{
		if(_rd)
		{
			_rd();
		}
	}

	if(_revents & ( POLLOUT))
	{
		if(_wr)
		{
			_wr();
		}
	}

	_eventHandling = false;
}

