#ifndef _MYTH52125_CONNECTOR_H_
#define _MYTH52125_CONNECTOR_H_

#include <codebase/base/StringArg.h>

#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <boost/scoped_ptr.hpp>
#include <codebase/net/InetAddr.h>

namespace myth52125
{
namespace net
{
class EventLoop;
class Channel;

class Connector
{
public:
    typedef boost::function<void (int fd)> newConCb;
    Connector(EventLoop *loop,const InetAddr &addr);
    ~Connector();
private:
    enum States{Connectint,
                Connected,
                Disconnect
                };
    EventLoop *_loop;
    InetAddr _serverAddr;
    bool _startConnected;
    boost::scoped_ptr<Channel> _channel;
    newConCb _cb;
    States _states;
    void connect();
    void updateChannel(int);
    void startInLoop();
    void stopInLoop();
    void handleWrite();
    void handleErr();
public:
    void start();
    void stop();



};







}



}



#endif
