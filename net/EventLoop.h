#ifndef _EVENTLOOP_H_M_
#define _EVENTLOOP_H_M_
//myth52125@myth52125-ThinkPad-T470p ~/github $ g++ -o test test.cc  ./codebase/base/Timestamp.h ./codebase/base/Timestamp.cc ./codebase/net/EventLoop.h ./codebase/net/EventLoop.cc -I./ -std=c++11
//

#include <codebase/base/Mutex.h>
#include <codebase/base/Timestamp.h>
#include <codebase/net/Channel.h>


#include <boost/function.hpp>
#include <codebase/net/Poller.h>
#include <codebase/net/PollPoller.h>


#include <vector>
namespace myth52125
{
namespace net
{

class Channel;
class Poller;

class EventLoop
{
public:
	typedef boost::function<void ()> Functor;
	typedef std::vector<Channel *> ChannelList;
	
	EventLoop();
	~EventLoop()
	{}
private:
	MutexLock _mutex;

	ChannelList _channels;
	Poller *_poller;
	bool _loop;
	bool _quit;
	bool _eventHanling;

	int _wakeFd;
	Channel *_wakeChannel;


	Timestamp _pollReturnTime;

	Channel	*_currentChannel;
	
public:
	void handleRead();
	void wakeup();
	void loop();
	void updateChannel(Channel *);

	void quit();	
};

}


}



#endif
