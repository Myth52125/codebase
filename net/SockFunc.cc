#include <codebase/net/SockFunc.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>  // snprintf
#include <strings.h>  // bzero
#include <sys/socket.h>
#include <unistd.h>
// #include <boost/implicit_cast.hpp>

namespace myth52125
{
namespace net
{
namespace socket
{


const struct sockaddr *sockaddr_cast(const struct sockaddr_in *addr)
{
    return static_cast<const struct sockaddr*>(reinterpret_cast<const void*>(addr));
}
const struct sockaddr *sockaddr_cast(const struct sockaddr_in6 *addr)
{
    return static_cast<const struct sockaddr*>(reinterpret_cast<const void*>(addr));
}
struct sockaddr *sockaddr_cast(struct sockaddr_in *addr)
{
    return static_cast<struct sockaddr*>(reinterpret_cast<void*>(addr));
}

const struct sockaddr_in *scokaddr_in_cast(const struct sockaddr* addr)
{
    return static_cast<const struct sockaddr_in*>(reinterpret_cast<const void*>(addr));
}





int nonblock_fd(sa_family_t family)
{
    int sockfd=::socket(family,SOCK_STREAM,IPPROTO_TCP);
    return sockfd;
}
int connect(int sockfd,const struct sockaddr *addr)
{
    int ret = ::connect(sockfd,addr,static_cast<socklen_t>(sizeof(struct sockaddr_in)));
    return ret;
}
void bind(int sockfd,const struct sockaddr* addr)
{
    int ret = ::bind(sockfd,addr,static_cast<socklen_t>(sizeof(sockaddr_in)));

}
void listen(int sockfd)
{
    int ret = ::listen(sockfd,SOMAXCONN);
}

int accept(int sockfd,struct sockaddr_in *addr)
{
    socklen_t socklen = static_cast<socklen_t>(sizeof(*addr));
    int connfd = ::accept4(sockfd,sockaddr_cast(addr),
        &socklen,SOCK_NONBLOCK | SOCK_CLOEXEC);

    if(connfd < 0)
    {
        /* */
    }
    return connfd;
}

ssize_t read(int sockfd,void *buf,size_t len)
{
    return ::read(sockfd,buf,len);
}
ssize_t write(int sockfd,const void *buf,size_t len)
{
    return ::write(sockfd,buf,len);
}

void close(int sockfd)
{
    int ret = ::close(sockfd);
}

void shutdown_write(int sockfd)
{
    int ret = ::shutdown(sockfd,SHUT_WR);
}

void to_ip_port(char* buf,size_t len,const struct sockaddr *addr)
{
    
}
void to_ip(char* buf,size_t len,const struct sockaddr *addr)
{

}

void fill_addr(const char *ip,uint16_t port,struct sockaddr_in *addr)
{
    addr->sin_family = AF_INET;
    addr->sin_port = htonl(port);
    int ret = ::inet_pton(AF_INET,ip,&addr->sin_addr);
}

int socket_error(int sockfd)
{
    int optval;
    socklen_t optlen = static_cast<socklen_t>(sizeof optval);
    int ret = ::getsockopt(sockfd,SOL_SOCKET,SO_ERROR,&optval,&optlen);
    
    return optval;
}




bool is_self_conn(int sockfd)
{
    
}






}    
}
}




