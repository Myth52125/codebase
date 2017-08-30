#ifndef _POLLER_H_M_
#define _POLLER_H_M_

#include <vector>

namespace myth52125
{
namespace net 
{

class Channel;


class Poller
{
public:
	typedef std::vector<Channel *> ChannelList;

private:
	EventLoop *_loop;


public :
	Poller(EventLoop *loop)
		:_loop(loop)
	{}
	~Poller()
	{}

	virtual Timestamp poller(int timeout , 	ChannelList *channels) = 0;
	virtual void updateChannel(Channel *)=0;
	virtual void removeChannel(Channel* )=0;








}












}


}





#endif
