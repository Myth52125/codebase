
#include <codebase/base/File.h>
#include <codebase/base/Debug.h>
#include <codebase/net/Channel.h>
#include <sys/eventfd.h>
#include <boost/bind.hpp>
#include <codebase/net/sockFunc.h>
#include <codebase/net/Poller.h>
#include <codebase/net/PollPoller.h>
#include <codebase/net/EventLoop.h>

using namespace myth52125;
using namespace myth52125::net;
using namespace myth52125::base;


int createEventFd()
{
    int fd = ::eventfd(0,EFD_NONBLOCK | EFD_CLOEXEC);
    return fd;
}



EventLoop::EventLoop()
    :_wakeup(createEventFd()),_wakeupChannel(new Channel(_wakeup,this)),
    _islooping(false),_quit(false),
    _poller(new PollPoller(this))
{
    _wakeupChannel->setReadCallBack(
            boost::bind(&EventLoop::wakeupChannelRead,this));
    _wakeupChannel->canRead();
}

void EventLoop::wakeupChannelRead()
{
    uint64_t wake;
    ssize_t ret=socket::read(_wakeup,&wake,sizeof(wake));

}
void EventLoop::wakeup()
{
    uint64_t wake=1;
    ssize_t ret = socket::write(_wakeup,&wake,sizeof(wake));
}   

void EventLoop::loop()
{
    assert(!_islooping);
    
    _islooping=true;
    _quit =false;
    Channel *_cur;
    while(_islooping)
    {
        _readyChannels.clear();
        _lastReadyTime = _poller->poll(10000,&_readyChannels);

        _eventHandling = true;
        for(ChannelList::iterator it = _readyChannels.begin();
            it != _readyChannels.end();it++)
        {
            _cur = *it;
            _cur->handleEvent();
        }
        _cur=NULL;
        _eventHandling = false;
        //wait
    }
    _islooping=false;
}

void EventLoop::updateChannel(Channel *channel)
{
    assert(channel->inLoop(this));
    _poller->updateChannel(channel);
}

void EventLoop::removeChannel(Channel *channel)
{
    assert(channel->inLoop(this));
    _poller->removeChannel(channel);
}


