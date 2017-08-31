#ifndef _CHANNEL_H_M_
#define _CHANNEL_H_M_

#include <boost/function.hpp>
#include <codebase/base/Timestamp.h>
#include <codebase/net/EventLoop.h>
#include <poll.h>
namespace myth52125
{
namespace net
{
class EventLoop;

class Channel
{
public:
	typedef boost::function<void ()> EventCallback;
	typedef boost::function<void (Timestamp)> ReadEventCallback;

private:
	EventLoop *_loop;
	int _fd;
	int _events;
	int _revents;
	int _index;
	
	bool _eventHandling;
	bool _addedToLoop;

	EventCallback _wr;
	EventCallback _rd;
	EventCallback _er;
	EventCallback _cl;
	void update();
public:
	static const int PReadEvent = POLLIN | POLLPRI;
	static const int PWriteEvent = POLLOUT;
	static const int PNoneEnvent = 0;


	Channel(EventLoop *loop, int fd);
	~Channel();


	void setWriteCallback(const EventCallback &wr)
	{
		_wr=wr;
	}

	void setReadCallback(const EventCallback &rd)
	{
		_rd=rd;

	}

	void setErrorCallback(const EventCallback &er)
	{
		_er=er;
	}
	void setCloseCallback(const EventCallback &cl)
	{
		_cl=cl;
	}

	void waitRead()
	{
		_events|=PReadEvent;
		update();
	}

	void waitWrite()
	{
		_events|=PWriteEvent;
		update();
	}

	void endWaitWrite()
	{
		_events &= ~PWriteEvent;
		update();
	}

	void endWaitRead()
	{
		_events &= ~PReadEvent;
		update();
	}

	void endWaitAll()
	{
		_events = 0;
		update();
	}

	int events()
	{
		return _events;
	}

	void revents(int re)
	{
		_revents=re;
	}

	int fd()
	{
		return _fd;
	}

	void index(int i)
	{
		_index=i;
	}

	int index()
	{
		return _index;
	}
	
	void handleEvent(Timestamp when);

	void remove();





};






}
}


#endif
