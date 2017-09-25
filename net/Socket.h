#ifndef _MYTH52125_Socket_H_
#define _MYTH52125_Socket_H_

#include <codebase/base/StringArg.h>
#include <codebase/net/InetAddr.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <strings.h>  // bzero

namespace myth52125
{
namespace net
{


class Socket
{
public:
    explicit Socket(int fd)
        :_fd(fd)
        {

        }
    ~Socket()
    {
        close(_fd);
    }
private:
    int _fd;
public:
    void bind(const InetAddr *addr)
    {
        socket::bind(_fd,addr->sockaddr());
    }
    void listen()
    {
        socket::listen(_fd);
    }
    int accept(InetAddr *peer)
    {
        struct sockaddr_in addr;
        bzero(&addr,sizeof(addr));
        int con = socket::accept(_fd,&addr);
        if(peer && con>0)
        {
            peer->sockaddr(addr);
        }
        return con;
    }

    int fd()
    {
        return _fd;
    }

};







}



}



#endif
