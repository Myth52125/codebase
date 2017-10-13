#include <codebase/base/EveryThread.h>
#include <codebase/base/MutexLock.h>

#include <iostream>
#include <unistd.h>
using namespace myth52125::base;
using namespace std;

int main()
{
    MutexLock lock;
    MutexLockGuard hhah(lock);
    
    cout<<gettid()<<endl;
}

