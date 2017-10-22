#ifndef _MYTH52125_THREAD_H_
#define _MYTH52125_THREAD_H_

#include <codebase/base/EveryTHread.h>
#include <codebase/base/StrArg.h>

#include <functional>

namespace myth52125
{


class Thread
{
public: 
    typedef function<void ()> ThreadFunc;
    explicit Thread(const ThreadFunc&,const StrArg& = StrArg("No name"));
private:
    ThreadFunc m_func;
    pthread_t m_tid;
    StrArg m_thread_name;

public:



};

}

#enfif  //_MYTH52125_THREAD_H_

//http://download.csdn.net/download/yyscamper/3072128