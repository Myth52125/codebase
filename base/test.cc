#include "Debug.h"
#include "StringArg.h"

int main()
{
	using namespace myth52125::base;
	ERRLESSZERO(0,"hah");
	MUTEXERR(0);

	StringArg s("asd");
	StringArg S1(s);
	debugMsg(s.c_str());
}
