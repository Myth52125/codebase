#ifndef _MYTH52125__H_
#define _MYTH52125__H_

#include <codebase/base/StringArg.h>

namespace myth52125
{
namespace net
{
namespace socket
{

int createSocket(sa_family_t family)
{
    int sockfd = ::socket(family, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
    return sockfd;
}
int connect(int fd, const struct sockaddr *addr)
{

}
void bind(int fd, const struct sockaddr *addr)
{

}
void listen(int fd)
{

}
int accept(int fd, struct sockaddr *addr)
{

}

size_t read(int fd, void *buf, size_t len)
{

}
size_t write(int fd, const void *buf, size_t counts)
{

}

void close(int fd)
{

}
void shutdownWrite(ing fd)
{

}

void getIpPort(char *buf, size_t len, const struct sockaddr *addr)
{

}
void getIp(char *buf,size_t len,const struct sockaddr *addr)
{

}

void fillAddr(const char *ip,uint64_t port,struct sockaddr *addr)
{

}


const struct sockaddr* sockaddr_cast(const struct sockaddr_in* addr)
{
    return static_cast<const struct sockaddr*>(implicit_cast<const void*>(addr));
}
const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr* addr)
{
    return static_cast<const struct sockaddr_in*>(implicit_cast<const void*>(addr));
    
}

}
}
}

#endif
