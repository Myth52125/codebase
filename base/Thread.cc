#include <codebase/base/EveryThread.h>
#include <codebase/base/StrArg.h>
#include <codebase/base/EveryThread.h>

namespace auxiliary
{

struct ThreadData
{
    typedef myth52125::Thread::ThreadFunc ThreadFunc;
    
    ThreadData(const ThreadFunc &func,const StrArg &name,pid_t *tid)
        :mq_func(func),m_thread_name(name),mp_tid(tid)
    {
    }

    ThreadData mq_func;
    StrArg m_thread_name;
    pid_t* mp_tid;

    void run()
    {
        *mp_tid = EveryThread::gettid();
        ::prctl(PR_SET_NAME, m_thread_name.c_str());

        strcpy(myth52125::EveryThread::g_thread_name,
            m_thread_name.c_str());
        
        g_thread_tid = *mp_tid;

        try
        {
            mq_func();
        }
        catch
        {
            //
        }
    }
}

void *send_to_thread(void *arg)
{
    ThreadData *arg=static_cast<ThreadData *>(arg);
    data->run();
    delete data;
    return NULL;
}

}


using namespace myth52125;

Thread::Thread(const ThreadFunc& func,const StrArg& name)
    :m_func(func),m_thread_name(name)
{
    
}

