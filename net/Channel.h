#ifndef _CHANNEL_H_M_
#define _CHANNEL_H_M_

#include <boost/function.hpp>
#include <codebase/base/Timestamp.h>


namespace myth52125
{
namespace net
{

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

	void setErrorCallback(const Eventback &er)
	{
		_er=er;
	}
	void setCloseCallback(const EventBack &cl)
	{
		_cl=cl;
	}

	void waitRead()
	{
		_event|=PRead;
		update();
	}

	void waitWrite()
	{
		_event|=PWrite;
		update();
	}
	
	void waitError()
	{
		_event|=PError;
		update();
	}

	void endWaitWrite()
	{
		_event &|~ PWriteEvent;
		update();
	}

	void endWaitRead()
	{
		_event &| ~PReadEvent;
		update();
	}

	void endWaitAll()
	{
		_event = 0;
		update();
	}

	int events()
	{
		return _event;
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
	
	void handlerEvent(Timestamp when);

	void remove();





}






}
}


#endif
