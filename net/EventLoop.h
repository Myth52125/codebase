#ifndef _MYTH52125_EVENTLOOP_H_
#define _MYTH52125_EVENTLOOP_H_

#include <codebase/base/StringArg.h>
#include <codebase/net/Poller.h>
#include <codebase/net/PollPoller.h>
#include <memory>
#include <boost/scoped_ptr.hpp>
#include <codebase/base/MutexLock.h>

namespace myth52125
{
namespace net
{

class Channel;
class Poller;

class EventLoop
{
public:
    typedef std::vector<Channel *> ChannelList;
    typedef boost::function<void ()> Task;
    
    EventLoop();
    ~EventLoop();
private:
    int _wakeup;
    boost::scoped_ptr<Channel> _wakeupChannel;
    

    bool _islooping;
    bool _quit;
    bool _eventHandling;
    boost::scoped_ptr<Poller> _poller;
    
    ChannelList _readyChannels;
    Timestamp _lastReadyTime;

    std::vector<Task> queueTasks;
    MutexLock _lock;

    void wakeupChannelRead();
    
public:
    void loop();
    void quit();
    void updateChannel(Channel *);
    void removeChannel(Channel *);

    void wakeup();
    void add(const Task &task);
};


}



}



#endif
