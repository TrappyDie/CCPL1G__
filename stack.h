#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
typedef struct {
 long input[100];
 int i;
}STACK;

STACK criar_stack(){
STACK s;
s.i = 0;
return s;
}

#define PUSH(s,n)  s.input[s.i++]=n;
#define POP(s)  s.input[s.i--];
#define SUM(s) PUSH(s,(POP
//#define

#endif // STACK_H_INCLUDED
