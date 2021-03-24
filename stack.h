#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <math.h>
typedef struct {
 long input[100];
 int i;
}STACK;

STACK criar_stack(){
STACK s;
s.i = 0;
return s;
}

#define PUSH(s,n)  s.input[s.i++]=n
#define POP(s)     s.input[--s.i]



#define SUM(s)     PUSH(s,POP(s) + POP(s))

#define LESS(s)    {			\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, X - Y);				\
}

#define DIV(s)     				\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, pow(X, Y));			\
}

#define MULT(s)    PUSH(s,POP(s) * POP(s))

#define EXP(s) {				\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, pow(X, Y));			\
}

#define RES(s)     PUSH(s,POP(s) % POP(s))
#define INC(s)     PUSH(s,POP(s)++)
#define DEC(s)     PUSH(s,POP(s)--)
#define AND(s)     PUSH(s,(POP(s) & POP(s)))
#define OR(s)      PUSH(s,(POP(s) | POP(s)))
#define XOR(s)     PUSH(s,(POP(s) ^ POP(s)))
#define NOT(s)     PUSH(s,(~POP(s)))

#endif
