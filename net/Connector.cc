
#include <codebase/base/Debug.h>
#include <codebase/net/Connector.h>
#include <codebase/net/EventLoop.h>
#include <codebase/net/SockFunc.h>
#include <codebase/net/Channel.h>
#include <boost/bind.hpp>

using namespace myth52125;
using namespace myth52125::net;

Connector::Connector(EventLoop *loop,const InetAddr &addr)
    :_loop(loop),_serverAddr(addr),_states(Disconnect)
{

}

void Connector::start()
{
    _startConnected=true;
    _loop->add(boost::bind(&Connector::startInLoop,this));
}

void Connector::startInLoop()
{
    if(_startConnected)
    {
        connect();
    }
}

void Connector::connect()
{
    int fd = socket::createSocket(_serverAddr.famliy());
    int ret = socket::connect(fd,_serverAddr.sockaddr());
    if(ret == 0)
    {
        updateChannel(fd);
    }
}

void Connector::updateChannel(int fd)
{
    _channel.reset(new Channel(fd,_loop));
    _channel->setWriteCallBack(
        boost::bind(&Connector::handleWrite,this)
    );
    _channel->serErrorCallBack(
        boost::bind(&Connector::handleErr,this)
    );
}

void Connector::stop()
{
    _startConnected=false;
    _loop->add(
        boost::bind(&Connector::stopInLoop,this)
    );
}

void Connector::stopInLoop()
{
    _channel->disableAll();
    _channel->remove();
}


