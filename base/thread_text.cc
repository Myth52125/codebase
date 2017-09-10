#include <codebase/base/Thread.h>
#include <stdio.h>

void func01()
{
    printf("func01 \n");
}

void func02()
{
    printf("func02 \n");
}

using namespace myth52125;
using namespace myth52125::base;
// /using namespace myth52125::;


int main()
{
    Thread t01(func01);
    t01.start();

}