#include <codebase/base/EveryThread.h>
#include <codebase/base/StrArg.h>
#include <codebase/base/Thread.h>
#include <sys/prctl.h>
#include <pthread.h>
namespace myth52125
{

namespace auxiliary
{
using namespace base;

struct ThreadData
{
    typedef Thread::ThreadFunc ThreadFunc;
    
    ThreadData(const ThreadFunc &func,const StrArg &name,pid_t *tid,Condition *cond)
        :mq_func(func),m_thread_name(name),mp_tid(tid),mp_cond(cond)
    {
    }

    ThreadFunc mq_func;
    StrArg m_thread_name;
    pid_t* mp_tid;
    Condition *mp_cond;
    void run()
    {
        *mp_tid = myth52125::thread::gettid();
        ::prctl(PR_SET_NAME, m_thread_name.c_str());

        
        strcpy(myth52125::thread::g_thread_name,
            m_thread_name.c_str());
        
        myth52125::thread::g_thread_tid = *mp_tid;
        mp_cond->notify();
        try
        {
            mq_func();
        }
        catch(...)
        {
            //
        }
    }
};

void *run_in_thread(void *arg)
{
    ThreadData *data=static_cast<ThreadData *>(arg);
    data->run();
    delete data;
    return NULL;
}

}
}


using namespace myth52125;
using namespace myth52125::base;


Thread::Thread(const ThreadFunc& func,const StrArg& name)
    :m_func(func),m_thread_name(name),m_mutex(),m_cond(m_mutex),
    mb_started(false),mb_joined(false)
{
    
}

Thread::~Thread()
{
    if(mb_started && !mb_joined )
    {
        pthread_detach(m_pthread);
    }
}

void Thread::start()
{
    assert(!mb_started);
    auxiliary::ThreadData *data
        =new auxiliary::ThreadData(m_func,m_thread_name,&m_tid,&m_cond);
    mb_started = true;
    int ret = ::pthread_create(&m_pthread,NULL,auxiliary::run_in_thread,data);
    if(ret != 0)
    {
        mb_started = false;
        delete data;
    }else{
        m_cond.wait();
    }
}

void Thread::join()
{
    assert(mb_started);
    assert(!mb_joined);
    mb_joined =true;
    pthread_join(m_pthread,NULL);
}

const StrArg &Thread::name() const  
{
    return m_thread_name;
}

pid_t Thread::tid()
{
    return m_tid;
}