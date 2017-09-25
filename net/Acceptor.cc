
#include <codebase/base/Debug.h>
#include <codebase/net/Acceptor.h>
#include <codebase/net/EventLoop.h>
#include <codebase/net/InetAddr.h>
#include <codebase/net/SockFunc.h>
#include <boost/bind.hpp>


using namespace myth52125;
using namespace myth52125::net;

Acceptor::Acceptor(EventLoop *loop,const InetAddr *listen,bool reuseport)
    :_loop(loop),_acceptSocket(socket::createSocket(listen->famliy())),
    _acceptChannel(_acceptSocket.fd(),_loop),_listening(false)
{
    _acceptSocket.bind(listen);
    _acceptChannel.setReadCallBack(
        boost::bind(&Acceptor::handleRead,this)
    );
}

Acceptor::~Acceptor()
{
    _acceptChannel.disableAll();
    _acceptChannel.remove();
}

void Acceptor::handleRead()
{
    InetAddr peer;
    int con = _acceptSocket.accept(&peer);
    if(con>0)
    {
        if(_cb)
        {
            _cb(con,peer);
        }else{
            socket::close(con);
        }

    }else{

    }
}

void Acceptor::listen()
{
    _listening=true;
    _acceptSocket.listen();
    _acceptChannel.canRead();
}

