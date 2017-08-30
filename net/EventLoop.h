#ifndef _EVENTLOOP_H_M_
#define _EVENTLOOP_H_M_


#include <codebase/base/Mutex.h>
#include <codebase/base/Timestamp.h>
#include <codebase/net/Channel.h>


#include <boost/function.hpp>


#include <vector>
#include <>
namespace myth52125
{
namespace net
{

class Channel;


class EventLoop
{
public:
	typedef boost::function<void ()> Functor;
	typedef std::vector<Channel *> ChannelList;

private:
	MutexLock _mutex;

	ChannelList _channels;

	bool _loop;
	bool _quit;
	bool _eventHanling;

	int _wakeFd;
	Channel _wakeChannel;


	Timestamp _pollReturnTime;

	Channel	*_currentChannel;
	
public:
	void handleRead();
	void wakeup();
	void loop();


}

}


}



#endif
