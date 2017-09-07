#include "Debug.h"


class A
{
	public:
	A(int i,int ii)
		:_i(i),_ii(ii)
	{
		debugMsg("A()");	
	}
	int _i;
	int _ii;
};

class B
{
	public:
		B(int i,int ii)
			:_a(A(i,ii))
		{
		
		}

	A _a;
};


int main ()
{
	B b(1,1);

}
