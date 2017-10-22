#ifndef _MYTH52125_THREAD_H_
#define _MYTH52125_THREAD_H_

#include <codebase/base/EveryThread.h>
#include <codebase/base/StrArg.h>
#include <codebase/base/MutexLock.h>
#include <codebase/base/Condition.h>

#include <functional>

namespace myth52125
{

namespace base
{

class Thread
{
public: 
    typedef std::function<void ()> ThreadFunc;
    explicit Thread(const ThreadFunc&,const StrArg& = StrArg("No Name"));
    ~Thread();
private:
    ThreadFunc m_func;
    pid_t m_tid;
    StrArg m_thread_name;
    pthread_t m_pthread;

    bool mb_started;
    bool mb_joined;
    Condition m_cond;
    MutexLock m_mutex;

public:
    void start();
    void join();
    const StrArg& name() const;
    pid_t tid();

};

}
}

#endif  //_MYTH52125_THREAD_H_

//http://download.csdn.net/download/yyscamper/3072128