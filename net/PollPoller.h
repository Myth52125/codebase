#ifndef _POLLPOLLER_H_M_
#define _POLLPOLLER_H_M_



#include <codebase/net/Poller.h>
#include <codebase/net/EventLoop.h>

#include <vector>


namespace myth52125
{
namespace net
{


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


	virtual Timestamp poll(int timeout,ChannelList *);
	virtual void updataChannel(Channel *);
	virtual void removeChannel(Channel *);



};
















}









}




#endif 
