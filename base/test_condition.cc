#include "Condition.h"
#include <pthread.h>
#include <iostream>
#include "MutexLock.h"
using namespace myth52125::base;
MutexLock lock;
Condition con(lock);

void* fun(void *)
{
    std::cout<<"now wait"<<std::endl;
    con.wait();
    std::cout<<"wake up run"<<std::endl;
}

int main()
{
    MutexLockGuard l(lock);
    pthread_t t;

    int result=pthread_create(&t,NULL,fun,NULL);
    std::cout<<"result : "<<result<<std::endl;


    int i;
    while(std::cin>>i)
    {
        std::cout<<"i : "<<i<<std::endl;
        con.notify();
        std::cout<<"wake up"<<std::endl;
    }
    sleep(10);
}
