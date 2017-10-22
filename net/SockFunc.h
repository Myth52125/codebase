#ifndef _MYTH52125_SOCKFUNC_H_
#define _MYTH52125_SOCKFUNC_H_

#include <arpa/inet.h>

namespace myth52125
{
namespace net
{
namespace socket
{

int nonblock_fd(sa_family family);
int connect(int sockfd,const struct sockaddr *addr);
void bind(int sockfd,const struct sockaddr* addr);
void listenint(int sockfd);

int accept(int sockfd,struct sockaddr *addr);

ssize_t read(int sockfd,void *buf,size_t len);
ssize_t write(int sockfd,const void *buf,size_t len);

void close(int sockfd);
void shutdown_write(int sockfd);

void to_ip_port(char* buf,size_t len,const struct sockaddr *addr);
void to_ip(char* buf,size_t len,const struct sockaddr *addr);

void fill_addr(const char *ip,uint16_t port,struct sockaddr_in *addr);

int socket_error(int sockfd);


const struct sockaddr *sockaddr_cast(const struct sockaddr_in *addr);
const struct sockaddr *sockaddr_cast(const struct sockaddr_in6 *addr);
struct sockaddr *sockaddr_cast(struct sockadd_in *addr);

const struct sockaddr_in *scokaddr_in_cast(const struct sockaddr* addr);

bool is_self_conn(int sockfd);


}
}
}

#endif  //_MYTH52125_SOCKFUNC_H_