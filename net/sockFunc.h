#ifndef _MYTH52125__H_
#define _MYTH52125__H_

#include <codebase/base/StringArg.h>
#include <arpa/inet.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>  // snprintf
#include <strings.h>  // bzero
#include <sys/socket.h>
#include <unistd.h>
#include<boost/implicit_cast.hpp>

namespace myth52125
{
namespace net
{
namespace socket
{


const struct sockaddr* sockaddr_cast(const struct sockaddr_in* addr)
{
    return static_cast<const struct sockaddr*>(boost::implicit_cast<const void*>(addr));
}
const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr* addr)
{
    return static_cast<const struct sockaddr_in*>(boost::implicit_cast<const void*>(addr));
}

int createSocket(sa_family_t family)
{
    int sockfd = ::socket(family, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
    return sockfd;
}
int connect(int fd, const struct sockaddr *addr)
{
    ::connect(fd,addr,static_cast<socklen_t>(sizeof(sockaddr_in)));
}
void bind(int fd, const struct sockaddr *addr)
{
    ::bind(fd,addr,static_cast<socklen_t>(sizeof(sockaddr_in)));
}
void listen(int fd)
{
    ::listen(fd,INT16_MAX);
}
// int accept(int fd, struct sockaddr_in *addr)
// {
//     socklen_t socklen=static_cast<socklen_t>(sizeof(*addr));
//     int confd=::accept(fd,sockaddr_cast(addr),&socklen);
//     return confd;
// }

size_t read(int fd, void *buf, size_t len)
{
    return ::read(fd,buf,len);
}
size_t write(int fd, const void *buf, size_t counts)
{
    return ::write(fd,buf,counts);
}

void close(int fd)
{
    ::close(fd);
}
void shutdownWrite(int fd)
{
    shutdown(fd, SHUT_WR);
}
// void getIp(char *buf,size_t len,const struct sockaddr *addr)
// {
//     if(addr->sin_family == AF_INET)
//     {
//         const struct sockadd_in *addr4=sockaddr_in_cast(addr);
//         ::inet_ntop(AF_INET,addr4->sin_addr,buf,static_cast<socklen_t>(len));
//     }
// }


// void getIpPort(char *buf, size_t len, const struct sockaddr *addr)
// {
//     getIp(buf,len,addr);
//     size_t iplen=strlen(buf);
//     const struct sockadd_in *addr4=sockaddr_in_cast(addr);
//     uint16_t port = ntohs(addr4->sin_port);
//     snprintf(buf+iplen,len-iplen,":%d",port);

// }

void getAddr(const char *ip,uint64_t port,struct sockaddr_in *addr)
{
    addr->sin_family=AF_INET;
    addr->sin_port=htons(port);
    ::inet_pton(AF_INET,ip,&addr->sin_addr);
}



}
}
}

#endif
