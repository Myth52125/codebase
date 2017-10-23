#include <codebase/net/PollPoller.h>
// #include <codebase/net/EPollPoller.h>
#include <codebase/net/Poller.h>
using namespace myth52125;
using namespace myth52125::net;

class EventLoop;
Poller* Poller::setPoller(EventLoop *loop,int poller_type  )
{
    if(poller_type == POLL)
    {
        return new PollPoller(loop);
    // }else if(poller_type == EPOLL){
        // return new EpollPoller(loop);
    }
}


