#include <codebase/net/Channel.h>
#include <codebase/net/EventLoop.h>
#include <codebase/base/Timestamp.h>
#include <poll.h>

using namespace myth52125;
using namespace myth52125::base;
using namespace myth52125::net;

const int s_none_event = 0;
const int s_read_event=POLLIN | PRLLPRI;
const int s_write_event = POLLOUT;

Channel::Channel(EventLoop *loop,int fd)
    :mp_loop(loop),m_fd(fd),
    mb_in_loop(false),mb_in_handle(false)
    m_events(0),m_revents(0),m_index(-1)
{
    
}

Channel::~Channel()
{
    assert(!mb_in_loop);
    assert(!mb_in_handle);
    remove_channel(this);
}

void Channel::update()
{
    m_in_loop = true;
    loop->update_channel(this);
}
void Channel:remove()
{
    assert(m_in_loop);
    m_in_loop = false;
    loop->remove_channel(this);
}

void Channel::handle_event(Timestamp receive_time)
{
    m_in_handle = true;
    
    if((m_revents & POLLHUP) && !(m_revents & POLLIN)
    {
        if(m_close_cb)
        {
            m_close_cb();
        }
    }

    if(m_revents & ( POLLIN | POLLPRI | POLLRDHUP)
    {
        if(m_read_cb)
        {
            m_read_cb(receive_time);
        }
    }

    if(m_revents & POLLOUT)
    {
        if(m_write_cb)
        {
            m_write_cb();
        }
    }
    m_in_handle = false;
}


