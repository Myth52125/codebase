
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

//在loop线程中开始新建一个链接并链接到给定的服务端套接字
void Connector::start()
{
    _startConnected=true;
    _loop->add(boost::bind(&Connector::startInLoop,this));
}

//在loop线程中执行connect
void Connector::startInLoop()
{
    if(_startConnected)
    {
        connect();
    }
}

//该函数只会在loop线程中执行，但是还没加assert
//创建一个非阻塞套接字，然后开始链接。
//如果链接成功，那么将套接字包如Channel中，然后更新
void Connector::connect()
{
    int fd = socket::createSocket(_serverAddr.famliy());
    int ret = socket::connect(fd,_serverAddr.sockaddr());
    if(ret == 0)
    {
        updateChannel(fd);
    }
}

//将链接成功的套接字包入Chaanel中，并设置各种回调函数
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

//停止一个链接
void Connector::stop()
{
    _startConnected=false;
    _loop->add(
        boost::bind(&Connector::stopInLoop,this)
    );
}
//删除设置的Channel
void Connector::stopInLoop()
{
    _channel->disableAll();
    _channel->remove();
}


