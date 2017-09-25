#ifndef _MYTH52125_INETADDR_H_
#define _MYTH52125_INETADDR_H_

#include <codebase/base/StringArg.h>
#include <codebase/net/SockFunc.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <strings.h> // bzero

namespace myth52125
{
namespace net
{
using namespace myth52125::base;
class InetAddr
{
  public:
    explicit InetAddr(uint16_t port = 0, bool loopback = false)
    {
        bzero(&_addr, sizeof(_addr));
        _addr.sin_family = AF_INET;
        _addr.sin_port = port;
        //这里查一下头文件
        // _addr.sin_addr = ip;
    }

    explicit InetAddr(StringArg ip, uint16_t port)
    {
        bzero(&_addr, sizeof(_addr));
        _addr.sin_family = AF_INET;
        _addr.sin_port = port;
        socket::getAddr(ip.c_str(), port, &_addr);
    }
    explicit InetAddr(struct sockaddr_in &addr)
        : _addr(addr)
    {
    }

  private:
    struct sockaddr_in _addr;

  public:
    sa_family_t famliy() const
    {
        return _addr.sin_family;
    }
    const struct sockaddr *sockaddr() const
    {
        return socket::sockaddr_cast(&_addr);
    }
    void sockaddr(sockaddr_in &addr)
    {
        _addr = addr;
    }
};
}
}

#endif
