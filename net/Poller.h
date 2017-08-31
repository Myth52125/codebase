#ifndef _POLLER_H_M_
#define _POLLER_H_M_

#include <map>
#include <vector>
#include <codebase/net/EventLoop.h>
#include <codebase/base/Timestamp.h>


namespace myth52125
{
namespace net 
{

class Channel;
class EventLoop;

class Poller
{
public:
	typedef std::vector<Channel *> ChannelList;
	typedef std::map<int, Channel*> ChannelMap;
private:
	EventLoop *_loop;
protected:
	ChannelMap _channels;
public :
	Poller(EventLoop *loop)
		:_loop(loop)
	{}
	~Poller()
	{}

	virtual Timestamp poller(int timeout , 	ChannelList *channels) = 0;
	virtual void updateChannel(Channel *)=0;
	virtual void removeChannel(Channel* )=0;


};

}


}





#endif
