 */


#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <math.h>

/**
 * \brief Struct de stacks
 * @param input Array onde se vão guardar os valores do stack
 * @param i Inteiro usado para indicar a posicao de cada elemento do stack
 */
typedef struct {
 long input[100];
 int i;
}STACK;

/**
 * \brief Controi um stack
 * @returns O stack construido vazio
 */
STACK criar_stack(){
STACK s;
s.i = 0;
return s;
}

#define PUSH(s,n)  s.input[s.i++]=n
#define POP(s)     s.input[--s.i]



#define SUM(s)     PUSH(s,POP(s) + POP(s))

#define LESS(s)    {				\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, X - Y);			\
}

#define DIV(s)  {   				\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, X / Y);			\
}

#define MULT(s)    PUSH(s,POP(s) * POP(s))

#define EXP(s) {				\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, pow(X, Y));			\
}

#define RES(s)     PUSH(s,POP(s) % POP(s))
#define INC(s)     PUSH(s,++POP(s))
#define DEC(s)     PUSH(s,--POP(s))
#define AND(s)     PUSH(s,POP(s) & POP(s))
#define OR(s)      PUSH(s,POP(s) | POP(s))
#define XOR(s)     PUSH(s,POP(s) ^ POP(s))
#define NOT(s)     PUSH(s,~POP(s))

/**
 * /brief Função que dá print a um stack
 * @param j Inteiro que se usa para ir mudando a posição do elemento do stack que se vai imprimir
 */
 
void output(STACK s){
	for(int j = 0;j<s.i;j++)
		printf("%ld", s.input[j]);
		}

#endif