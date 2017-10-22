#ifndef _MYTH52125_POLLPOLLER_H_
#define _MYTH52125_POLLPOLLER_H_

#include <codebase/net/Poller.h>
#include <vector>
#include <codebase/base/Timestamp.h>

namespace myth52125
{

class EventLoop;
struct pollfd;
class PollPoller : public Poller
{
public:
    typedef std::vector<Channel *> ChannelList
    PollPoller(EventLoop *);
    virtual ~PollPoller() override;
private:
    typedef std::vector<struct pollfd> PollFdList;
    PollFdList mc_pollfds;
    
    void fill_ready_vecetor(int num,ChannelList*);
public:
    virtual poll(int timeout_ms,ChannelList* ready_channels) override;
    virtual void update_channel(Channel *channel) override;
    virtual void remove_channel(Channel *channel) override;
};

}

#endif  //_MYTH52125_POLLPOLLER_H_