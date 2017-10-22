#ifndef _MYTH52125_POLLER_H_
#define _MYTH52125_POLLER_H_

// #include <codebase/net/>

#include <vecotr>
#include <map>
#include <codebase/net/EventLoop.h>
#include <iterator>

namespace myth52125
{

namespace net
{

#define POLL 1
#define EPOLL 2

class Channel;

class Poller
{
public:
    typedef std::vector<Channel *> ChannelList;

    Poller(EventLoop *loop)
        :mp_loop(loop)
    {

    }
    virtual ~Poller();
private:
    EventLoop *mp_loop;
protected:
    typedef std::map<int,Channel*> ChannelMap;
    ChannelMap mc_channels;

public:
    virtual Timestamp poll(int timeout_ms,ChannelList *) =0;
    virtual update_channel(Channel *) = 0;
    virtual remove_channel(Channel *)= 0;
    virtual has_channel(Channel *) const
    {
        ChannelMap::iterator it=mc_channels.find(channel->fd());
        return it != mc_channels.end() && it->second == channel;
    }
    
    static Poller* setPoller(EventLoop *);

};
}
}

#endif  //_MYTH52125_POLLER_H_