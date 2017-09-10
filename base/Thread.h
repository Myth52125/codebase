#ifndef _MYTH52125_THREAD_H_
#define _MYTH52125_THREAD_H_

#include <boost/function.hpp>
#include <codebase/base/StringArg.h>

namespace myth52125
{
namespace base
{


class Thread
{
public:
    typedef boost::function<void ()> Func;
    Thread(const Func &func, const StringArg &name = StringArg("no nome"));
    ~Thread();
private:
    pthread_t _pthread;
    Func _func;
    StringArg _name;
    bool _started;
    bool _joined;

public:
    void start();
    void join();



};







}



}



#endif
