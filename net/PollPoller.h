#ifndef _POLLPOLLER_H_M_
#define _POLLPOLLER_H_M_



#include <codebase/net/Poller.h>
#include <poll.h>

#include <vector>


namespace myth52125
{
namespace net
{

class EventLoop;
class PollPoller :public Poller
{
public:
	typedef std::vector<Channel *> ChannelList;
	typedef std::vector<struct 	pollfd> PollFdList;
	


private:
	PollFdList 	_pollFdList;
	
	void fillReadyChannel(int num, ChannelList *);

public:
	PollPoller(EventLoop * loop)
		:Poller(loop)
	{
	}
	~PollPoller()
	{}


	virtual Timestamp poller(int timeout,ChannelList *);
	virtual void updateChannel(Channel *);
	virtual void removeChannel(Channel *);



};
















}









}




#endif 
