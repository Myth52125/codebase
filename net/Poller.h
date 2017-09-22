#ifndef _MYTH52125_POLLER_H_
#define _MYTH52125_POLLER_H_

#include <codebase/base/StringArg.h>
#include <codebase/base/Timestamp.h>
#include <vector>
#include <map>
#include <poll.h>
#include <codebase/net/Channel.h>
namespace myth52125
{
namespace net
{
using namespace myth52125::base;
class EventLoop;

class Poller
{
public:
    Poller(EventLoop *loop)
        :_eventLoop(loop)
    {

    }

    virtual ~Poller()=0;

    typedef std::vector<Channel*> ChannelList;
    typedef std::map<int, Channel*> ChannelMap;
    typedef std::vector<struct pollfd> PollFdList;
    
protected:
    ChannelMap _channels;
    EventLoop *_eventLoop;
    
public:
    virtual Timestamp poll(int ,ChannelList *)=0;
    virtual void updateChannel(Channel *)=0;
    virtual void removeChannel(Channel *)=0;
    bool hasChannel(Channel *channel)
    {
        ChannelMap::iterator it = _channels.find(channel->fd());
        return it!=_channels.end();
    }
};







}



}



#endif
