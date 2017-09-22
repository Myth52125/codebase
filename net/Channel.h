#ifndef _MYTH52125_CHANNEL_H_
#define _MYTH52125_CHANNEL_H_

#include <codebase/base/StringArg.h>
#include <boost/function.hpp>
#include <codebase/base/Timestamp.h>

namespace myth52125
{
namespace net
{
using namespace myth52125::base;
class EventLoop;

class Channel
{
  public:
    typedef boost::function<void ()> CallBack;
    typedef boost::function<void (Timestamp)> ReadCallBack;

    Channel(int fd,EventLoop *loop);
    ~Channel();
    
  private:
    EventLoop *_loop;
    int _fd;
    int _index;

    int _events;
    int _revents;

    ReadCallBack _rd;
    CallBack _wr;
    CallBack _cl;

    void update();

  public:
    const static int ReadEvent;
    const static int WriteEvent;
    const static int NoneEvent;
    //set callback func
    void setReadCallBack(const ReadCallBack &rd) 
    {
        _rd = rd;
    }
    void setWriteCallBack(const CallBack &wr) 
    {
        _wr = wr;
    }
    void setCloseCallBack(const CallBack &cl) 
    {
        _cl = cl;
    }
    //set event and update to eventloop
    void canRead()
    {
        _events |= ReadEvent;
        update();
    }
    void canWrite()
    {
        _events |= WriteEvent;
        update();
    }
    void disableRead()
    {
        _events &= ~ReadEvent;
        update();
    }
    void disableWrite()
    {
        _events &= ~WriteEvent;
        update();
    }
    void disableAll()
    {
        _events = NoneEvent;
        update();
    }
    //return date for out
    int fd()
    {
        return _fd;
    }
    int index()
    {
        return _index;
    }
    int events()
    {
        return _events;
    }
    void index(int i)
    {
        _index = i;
    }
    void revents(int re)
    {
        _revents = re;
    }
    //remove 
    void remove();
    //handle event
    void handleEvents();    

    //
    void handleEvent()
    {

    }

    //
    bool inLoop(EventLoop *loop)
    {
        return loop == _loop;
    }
};
}
}

#endif
