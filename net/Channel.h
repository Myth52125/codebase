#ifndef _MYTH52125_CHANNEL_H_
#define _MYTH52125_CHANNEL_H_

#include <codebase/net/>
#include <functional>
#include <codebase/base/Timestamp.h>
namespace myth52125
{
namespace net
{
class EventLoop;

class Channel
{
public:
    typedef std::function<void ()> EventCB;
    typedef std::function<void (Timestamp)> EventReadCB;
    
    Channel(EventLoop *loop,int fd);
    ~Channel();

    static const int s_none_event;
    static const int s_read_event;
    static const int s_write_event;
private:
    EventLoop *mp_loop;
    int m_fd;
    
    int m_events;
    int m_revents;
    int m_index;
    
    EventCB m_write_cb;
    EventCB m_close_cb;
    EventCB m_error_cb;
    EventReadCB m_read_cd;

    bool mb_in_loop;
    bool mb_in_handle;

    void update();
    void remove();
    EventLoop *loop();
public:

    void handle_event(Timestamp);

    int fd()
    {
        return m_fd;
    }

    int index()
    {
        return m_index;
    }

    void index(int index)
    {
        m_index = index;
    }

    int events()
    {
        return m_events;
    }
    void events(int event)
    {
        m_events=event;
    }

    int revent()
    {
        return m_revents;
    }
    void revent(int revent)
    {
        m_revents = revent;
    }
    void enable_read()
    {
        m_events |= s_read_event;
        update();
    }
    void enable_write()
    {
        m_events |= s_write_event;
        update();
    }
    
    void disable_all()
    {
        m_events=s_none_event;
    }
    void disable_write()
    {
        m_events &= ~s_write_event;
    }
    void disable_read()
    {
        m_events &= ~s_read_event;
    }
    void set_read_callback(EventReadCB cb) 
    {
        m_read_cd=cb;
    }
    void set_write_callback(EventCB cb)
    {
        m_write_cb=cb;
    }
    void set_close_callback(EventCB cb)
    {
        m_close_cb=cb;
    }
    void set_error_callback(EventCB cb)
    {
        m_error_cb=cb;
    }

};

}
}

#endif  //_MYTH52125_CHANNEL_H_