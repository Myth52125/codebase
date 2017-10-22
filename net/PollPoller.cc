#include <codebase/net/EventLoop.h>
#include <codebase/net/Poller.h>
#include <codebase/base/Timestamp.h>
#include <errno.h>

using namespace myth52125;
using namespace myth52125::net;

PollPoller::PollPoller(EventLoop)
    :Poller(loop)
{

}

PollPoller::~PollPoller()
{

}

Timestamp PollPoller::poll(int timeout_ms,ChannelList* ready_channels)
{
    int read_nums = ::poll(&*mc_pollfds.begin(),mc_pollfds.size(),timeout_ms);
    int tmp_errno = errno;
    Timestamp ready_time();
    if(read_nums > 0)
    {
        fill_ready_vecetor(read_nums,ready_channels);
    }else if(read_nums == 0)
    {

    }else if(read_nums <0){
        /* */
    }
    return ready_time;
}

void PollPoller::fill_ready_vecetor(int read_nums,ChannelList *ready_channels)
{
    for(PollFdList::const_iterator cit_pollfd = mc_pollfds.cbegin();
        cit_pollfd != mc_pollfds.cend() && numEvents >0 ;++cit)
    {
        if(cit_pollfd -> revents >0)
        {
            --read_nums;
            ChannelMap::const_iterator cit_channel = mc_channels.find(cit_pollfd->fd);
            assert(cit_channel != mc_channels.end());
            Channel* channel = cit_channel->second;
            assert(channel->fd() == cit_channel->fd);
            channel->revents(cit_channel->revents);
            ready_channels.push_back(channel);
        }
    }
}
void PollPoller::updateChannel(Channel *channel)
{
    if(channel->index() <0)
    {
        assert(mc_channels.find(channel->fd()) == mc_channels.end());
        struct pollfd pfd;
        pfd.fd = channel->fd;
        pfd.events = static_cast<short>(channel->events());
        pfd.revents=0;
        mc_pollfds.push_back(pfd);
        int index = static_cast<short>(mc_pollfds.size()-1);
        channel->index(index);
        mc_channels[pfd.fd]=channel;
    }else{
        assert(mc_channels.find(channel->fd) != channels.end());
        assert(channel[channel->fd()] == channel);
        
        int index = channel->index();

        assert(index <= 0 && index < static_cast<int>(mc_pollfds.size()));
        
        struct pollfd &pfd=mc_pollfds[index];
        
        pfd.fd = channel->fd();
        pfd.events=static_cast<short>(channel->events());
        pfd.revent=0;
    }
}

void PollPoller::remove_channel(Channel *channel)
{
    assert(mc_channels.find(channel->fd) != channels.end());
    assert(channel[channel->fd()] == channel);
    int index = channel->index();
    const struct pollfd &pfd=mc_pollfds[index];
    /**/
    size_t n=mc_pollfds.erase(channel->fd());
    /**/
    if(static_cast<size_t>(index) != mc_pollfds.size()-1)
    {
        int m_channels_end = mc_pollfds.back().fd;
        iter_swap(mc_pollfds.begin()+index,mc_pollfds.end()-1);
        mc_channels[m_channels_end]->index(index);
    }
    mc_pollfds.pop_back();    
}

