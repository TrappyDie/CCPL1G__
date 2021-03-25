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
 * @def Soma os dois elementos que estão mais acima no stack
 */
#define SUM(s)   {   			\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s,X + Y);				\
}

/**
 * @def Subtrai o elemento mais acima no stack pelo elemento abaixo desse
 */
#define LESS(s) { 				\
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
 * @def Multiplica os dois elementos que estão mais acima no stack
 */
#define MULT(s) {				\
	long Y = POP(s);			\
	long X = POP(s);			\
	PUSH(s,X * Y);				\
}

/**
 * @def Coloca o elemento mais acima do stack como base e o elemento abaixo desse como expoente
 */
#define EXP(s) {				\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s, pow(X, Y));			\
}

/**
 * @def Calcula o resto da divisão entre o elemento mais acima no stack e o abaixo desse
 */
#define RES(s) {				\
	long Y = POP(s);			\
	long X = POP(s); 			\
	PUSH(s,X % Y);				\
}	

/**
 * @def Incrementa um elemento no stack
 */
#define INC(s) {    			\
	long Y = POP(s);			\
	PUSH(s,Y++);	 			\
}

/**
 * @def Decrementa um elemento do stack
 */
#define DEC(s) {				\
	long Y = POP(s);			\
     	PUSH(s,Y--);			\
}

/**
 * @def Faz a operação lógica "AND" em bitwise entre os dois elementos mais acima do stack
 */
#define AND(s) {			\
	long Y = POP(s);		\
	long X = POP(s);		\
        PUSH(s,X & Y);		\
}

/**
 * @def Faz a operação lógica "OR" em bitwise entre os dois elementos mais acima do stack
 */
#define OR(s) {				\
	long Y = POP(s);		\
	long X = POP(s);		\
        PUSH(s,X | Y);		\
}

/**
 * @def Faz a operação lógica "XOR" em bitwise entre os dois elementos mais acima do stack
 */
#define XOR(s) {     		\
	long Y = POP(s);		\
	long X = POP(s);		\
        PUSH(s,X ^ Y);		\
}

/**
 * @def Faz a operação lógica "NOT" em bitwise ao elemento no topo do stack
 */
#define NOT(s) {  			\
	long Y = POP(s);		\
        PUSH(s,~Y);			\
}

/**
 * /brief Funcao que da print a um stack
 * @param j Inteiro que se usa para ir mudando a posicao do elemento do stack que se vai imprimir
 */
 
void output(STACK s){
    for(int j = 0;j<s.i;j++){
		printf("%ld", s.input[j]);
    }
    printf("\n");
		}

#endif