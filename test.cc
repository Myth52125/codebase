#include <codebase/base/Thread.h>
#include <codebase/base/Timestamp.h>
#include <iostream>
#include <unistd.h>
using namespace myth52125::base;
void fun()
{
    std::cout<<"func"<<std::endl;
}
int main()
{
    TimeSpend time;
    Thread t(fun);
    t.start();
    sleep(1);
}