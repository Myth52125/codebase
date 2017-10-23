#include <codebase/net/EventLoop.h>
#include <codebase/net/Channel.h>
#include <sys/eventfd.h>
#include <functional>
#include <codebase/net/Poller.h>
#include <codebase/net/PollPoller.h>
#include <codebase/net/SockFunc.h>
// #include <codebase/net/Poller.h>
using namespace myth52125;
using namespace net;


namespace myth52125
{
namespace auxiliary
{
__thread EventLoop* t_loop = NULL;

int create_eventfd()
{
    int eventfd = ::eventfd(0,EFD_NONBLOCK | EFD_CLOEXEC);
    return eventfd;
}
}
}

using namespace myth52125;
using namespace myth52125::net;


EventLoop::EventLoop()
    :m_wakeup_fd(auxiliary::create_eventfd()),mp_poller(Poller::setPoller(this)),
    mb_in_handle(false),mb_looping(false),
    mp_wakeup_channel(new Channel(this,m_wakeup_fd))
{
    mp_wakeup_channel->set_read_callback(
        std::bind(&EventLoop::wakeup_channel_read,this)
    );
    mp_wakeup_channel->enable_read();
}

EventLoop::~EventLoop()
{
    mp_wakeup_channel->disable_all();
    mp_wakeup_channel->remove();
    socket::close(m_wakeup_fd);
    auxiliary::t_loop=NULL;
}


void EventLoop::loop()
{
    assert(!mb_looping);
    mb_looping = true;
    mb_quit = false;
    Timestamp m_poll_ready;
    while(!mb_quit)
    {
        mc_ready_channels.clear();
        m_poll_ready = mp_poller -> poll(100000,&mc_ready_channels);

        mb_in_handle = true;
        for(ChannelList::iterator it = mc_ready_channels.begin();
            it != mc_ready_channels.end();it++)
        {
            (*it)->handle_event(m_poll_ready);
        }
        mb_in_handle = false;
    }
}

void EventLoop::quit()
{
    mb_quit = false;
    wakeup_channel_wakeup();
}

void EventLoop::wakeup_channel_read()
{
    uint64_t one =1;
    ssize_t n = socket::read(m_wakeup_fd,&one,sizeof(one));
}

void EventLoop::wakeup_channel_wakeup()
{
    uint64_t one =1;
    ssize_t n = socket::write(m_wakeup_fd,&one,sizeof(one));
}
void EventLoop::remove_channel(Channel *channel)
{
    assert(channel->loop() == this);
    
    if(mb_in_handle)
    {
    }
    mp_poller->remove_channel(channel);
}