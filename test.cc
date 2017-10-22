#include <codebase/base/EveryThread.h>
#include <codebase/base/MutexLock.h>
#include <codebase/base/EveryThread.h>
#include <iostream>
#include <unistd.h>
#include <codebase/base/Thread.h>
using namespace myth52125::base;
using namespace myth52125::thread;

using namespace std;

// extern char g_thread_name[32];

void func()
{
    // cout<<g_thread_name<<endl;
    cout<<"000"<<endl;
}

int main()
{
    MutexLock lock;
    MutexLockGuard hhah(lock);
    
    cout<<gettid()<<endl;

    Thread t(func);
    t.start();


    
    cout<<"endl"<<endl;
    sleep(1000);
}

