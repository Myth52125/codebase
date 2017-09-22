
#include <codebase/base/File.h>
#include <codebase/base/Debug.h>
#include <poll.h>
#include <codebase/net/Channel.h>
#include <codebase/net/EventLoop.h>
using namespace myth52125;
using namespace myth52125::net;

const int Channel::ReadEvent = POLLIN | POLLPRI;
const int Channel::WriteEvent = POLLOUT;
const int Channel::NoneEvent = 0;



Channel::Channel(int fd,EventLoop *loop)
    :_fd(fd),_loop(loop),
    _index(0),_events(0),_revents(0)
{

}

Channel::~Channel()
{

}

void Channel::update()
{
    _loop->updateChannel(this);
}
void Channel::remove()
{
    _loop->removeChannel(this);
}

