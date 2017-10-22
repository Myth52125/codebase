#include <codebase/base/EveryThread.h>
#include <codebase/base/MutexLock.h>
#include <codebase/base/EveryThread.h>
#include <iostream>
#include <unistd.h>
#include <codebase/base/Thread.h>
using namespace myth52125::base;
using namespace myth52125::thread;

using namespace std;

extern __thread char myth52125::thread::g_thread_name[32];
extern __thread pid_t myth52125::thread::g_thread_tid;



void func()
{
    cout<<g_thread_name<<" "<<g_thread_tid<<endl;
    cout<<"new threadd run"<<endl;
}

int main()
{
    MutexLock lock;
    MutexLockGuard hhah(lock);
    
    cout<<gettid()<<endl;

    Thread t(func);
    t.start();

    t.join();

}

