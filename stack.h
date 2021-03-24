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
// 5 4 # -> 5^4
#define PUSH(s,n)  s.input[s.i++]=n
#define POP(s)     s.input[--s.i]

/*
 * Havia aqui uma data de problemas de parenteses
 * São macros, não ponham os ; porque vai criar problemas
 */

#define SUM(s)     PUSH(s,POP(s) + POP(s))
#define LESS(s)    PUSH(s,POP(s) - POP(s))
#define DIV(s)     PUSH(s,POP(s) / POP(s))
#define MULT(s)    PUSH(s,POP(s) * POP(s))
// Não se pode fazer isto por várias razões
//#define EXP(s)     PUSH(s,pow(POP(s.input[s.i--]),POP(s.input[s.i)))
// Copiem o que eu fiz para a subtração e divisão
// A vossa divisão também está com problemas porque vai usar os operadores numa ordem errada

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

#endif // STACK_H_INCLUDED
