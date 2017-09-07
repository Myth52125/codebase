#ifndef _MYTH52125_DEBUG_H_
#define _MYTH52125_DEBUG_H_


#include <stdio.h>


#define ERRLESSZERO(n,msg) {if(n < 0) printf("Error :%s  :in file: %s  func: %s   line %d  \n",msg,__FILE__,__func__,__LINE__);}

#define MUTEXERR(n) {ERRLESSZERO(n,"Mutex fail ");}

#define debugMsg(msg) {ERRLESSZERO(0,msg);}

#define NULLERR(n,msg) {if(NULL == n) {ERRLESSZERO(0,msg); }}

#define NOTZEROERR(n,msg) {if(n != 0) { printf("Error :%s : in file : %s , func : %s , line %d \n",\
		msg,__FILE__,__func__,__LINE__);}}



#endif
