#ifndef _MYTH52125_EVENTLOOP_H_
#define _MYTH52125_EVENTLOOP_H_

#include <codebase/base/StrArg.h>
#include <functional>
#include <vector>
#include <codebase/base/Timestamp.h>

namespace myth52125
{
namespace net
{

class Channel;
class Poller;
class EventLoop
{
public:
    typedef std::function<void ()> Function;
    EventLoop();
    ~EventLoop();

private:
    typedef std::vector<Channel*> ChannelList;

    int m_wakeup_fd;
    Channel* mp_wakeup_channel;
    bool mb_looping;
    bool mb_quit;
    bool mb_in_handle;
    Timestamp m_poll_ready;
    ChannelList mc_ready_channels;
    Poller *mp_poller;
public:
    void loop();
    void quit();
    
};

}
}

#endif //_MYTH52125_EVENTLOOP_H_