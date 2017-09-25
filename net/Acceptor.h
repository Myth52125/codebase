#ifndef _MYTH52125_ACCEPTOR_H_
#define _MYTH52125_ACCEPTOR_H_

#include <codebase/base/StringArg.h>
#include <codebase/net/Socket.h>
#include <codebase/net/Channel.h>
#include <boost/function.hpp>



namespace myth52125
{
namespace net
{

class EventLoop;

class Acceptor
{
public:
    typedef boost::function<void (int sockfd,
        const InetAddr&)> ConCallack;

    Acceptor(EventLoop *loop,const InetAddr *listen,bool reuseport);
    ~Acceptor();
private:
    EventLoop *_loop;
    Socket _acceptSocket;
    Channel _acceptChannel;

    bool _listening;
    ConCallack _cb;
    void handleRead();
public:
    void setCallBack(ConCallack &cb)
    {
        _cb=cb;
    }
    void listen();
    bool listening()
    {
        return _listening;
    }


};







}



}



#endif
