
#include <codebase/base/Debug.h>
#include <codebase/base/EveryThread.h>
#include <sys/prctl.h>
#include <codebase/base/Thread.h>


namespace myth52125
{
namespace base
{
namespace thread
{
	
    
}
namespace tools
{

struct ThreadData
{
    typedef boost::function<void ()> Func;
    
    Func _func;
    StringArg _name;
    ThreadData(Func &func, const StringArg &name)
        :_func(func),_name(name)
    {
        _func();        
    }
    void run()
    {
        
        _func();
    }

};


void *bindForThread(void *data)
{   
    printf("bbinf i");
    ::prctl(PR_SET_NAME, "_threadName");
    ThreadData *_data = static_cast<ThreadData *>(data);
    _data->run();
}

}

}

}

using namespace myth52125;
using namespace myth52125::base::thread;

using namespace myth52125::base;
Thread::Thread(const Func &func, const StringArg &name)
    :_func(func),_name(name),
    _started(false),_joined(false)
{
    printf("func : %d \n",_func == NULL);
    
}



void Thread::start()
{
    _started = true;
    tools::ThreadData *data =new tools::ThreadData(_func,_name);
    int result = pthread_create(&_pthread,NULL,&tools::bindForThread,data);
    delete data;
    printf("pthread create result %d \n",result);
}

void Thread::join()
{
    int result = pthread_join(_pthread,NULL);
}

Thread::~Thread()
{
    if(!_joined)
    {
        join();
    }
}
