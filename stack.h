/**
 * @file Funcao onde estao definidos os stacks 
 */


#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <math.h>

/**
 * @struct Stack
 * \brief Struct de stacks
 * @param input Array onde se vao guardar os valores do stack
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

/**
 * @def Coloca um elemento num stack
 */
#define PUSH(s,n)  s.input[s.i++]=n

/**
 * @def Retira um elemento de um stack
 */
#define POP(s)     s.input[--s.i]

/**
 * @def Soma os dois elementos que estao mais acima no stack
 */
#define SUM(s)     PUSH(s,POP(s) + POP(s))

/**
 * @def Subtrai o elemento mais acima no stack pelo elemento abaixo desse
 */
#define LESS(s)    {			\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, X - Y);				\
}

/**
 * @def Divide o elemento mais acima no stack pelo elemento abaixo desse
 */
#define DIV(s)  {   			\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, X / Y);				\
}

/**
 * @def Multiplica os dois elementos que estao mais acima no stack
 */
#define MULT(s)    PUSH(s,POP(s) * POP(s))

/**
 * @def Coloca o elemento mais acima do stack como base e o elemento abaixo desse como expoente
 */
#define EXP(s) {				\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, pow(X, Y));			\
}

/**
 * @def Calcula o resto da divisao entre o elemento mais acima no stack e o abaixo desse
 */
#define RES(s)     PUSH(s,POP(s) % POP(s))

/**
 * @def Incrementa um elemento no stack
 */
#define INC(s)     PUSH(s,POP(s)++)

/**
 * @def Decrementa um elemento do stack
 */
#define DEC(s)     PUSH(s,POP(s)--)

/**
 * @def Faz a operação logica "AND" em bitwise entre os dois elementos mais acima do stack
 */
#define AND(s)     PUSH(s,(POP(s) & POP(s)))

/**
 * @def Faz a operação logica "OR" em bitwise entre os dois elementos mais acima do stack
 */
#define OR(s)      PUSH(s,(POP(s) | POP(s)))

/**
 * @def Faz a operação logica "XOR" em bitwise entre os dois elementos mais acima do stack
 */
#define XOR(s)     PUSH(s,(POP(s) ^ POP(s)))

/**
 * @def Faz a operação logica "NOT" em bitwise ao elemento no topo do stack
 */
#define NOT(s)     PUSH(s,(~POP(s)))

/**
 * /brief Funcao que da print a um stack
 * @param j Inteiro que se usa para ir mudando a posicao do elemento do stack que se vai imprimir
 */
 
void output(STACK s){
	for(int j = 0;j<s.i;j++)
		printf("%ld", s.input[j]);
		}

#endif
