
#include <codebase/base/File.h>
#include <codebase/base/Debug.h>
#include <codebase/net/PollPoller.h>
#include <assert.h>
#include <poll.h>
#include <codebase/net/Channel.h>

using namespace myth52125;
using namespace myth52125::net;


Timestamp PollPoller::poll(int timeout,ChannelList *readyChannels) 
{
    int readyCounts=::poll(&*_pollFds.begin(),_pollFds.size(),timeout);
    Timestamp now;
    if(readyCounts >0 )
    {
        fillReadyChannels(readyCounts,readyChannels);
    }
    return now;
}

PollPoller::~PollPoller()
{

}

Timestamp PollPoller::fillReadyChannels(int counts,ChannelList *readyChannels)
{
    for(PollFdList::iterator it = _pollFds.begin();
        it != _pollFds.end();it++)
    {
        if(counts>0)
        {
            ChannelMap::iterator fdToChannel = _channels.find(it->fd);
            assert(fdToChannel != _channels.end());
            Channel *channel = fdToChannel->second;
            channel->revents(it->revents);
            readyChannels->push_back(channel);
            counts--;
        }
    }
}


void PollPoller::updateChannel(Channel *channel) 
{
    if(channel->fd()<0)
    {
        struct pollfd pfd;
        pfd.fd=channel->fd();
        pfd.events=channel->events();
        pfd.revents=0;
        _pollFds.push_back(pfd);
        int index = static_cast<int>(_pollFds.size());
        channel->index(index);
        _channels[pfd.fd]=channel;

    }else{
        int index = channel->index();
        struct pollfd &pfd=_pollFds[index];
        pfd.events=channel->events();
        pfd.revents=0;
    }
}
void PollPoller::removeChannel(Channel *channel) 
{
    int index = channel->index();
    const struct pollfd &pfd=_pollFds[index];
    size_t n=_channels.erase(channel->fd());
    if(static_cast<size_t>(index) != _pollFds.size()-1)
    {
        int endFd=_pollFds.back().fd;
        iter_swap(_pollFds.begin()+index,_pollFds.end()-1);
        _channels[endFd]->index(index);

    }
    _pollFds.pop_back();
}