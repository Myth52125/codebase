#ifndef _MYTH52125_POLLPOLLER_H_
#define _MYTH52125_POLLPOLLER_H_

#include <codebase/base/StringArg.h>
#include <vector>
#include <map>
#include <codebase/net/Poller.h>

namespace myth52125
{
namespace net
{

class Channel;
class EventLoop;

class PollPoller : public Poller
{
public:
    PollPoller(EventLoop *loop)
        :Poller(loop)
    {

    }
    virtual ~PollPoller();

    typedef std::vector<Channel*> ChannelList;
    typedef std::map<int, Channel*> ChannelMap;
    
private:
    PollFdList _pollFds;
    Timestamp fillReadyChannels(int,ChannelList*);
public:
    virtual Timestamp poll(int ,ChannelList *) ;
    virtual void updateChannel(Channel *) ;
    virtual void removeChannel(Channel *) ;
};


}



}



#endif
