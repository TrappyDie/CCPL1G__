/**
 * @file Funcao onde estao definidos os stacks 
 */


#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

#define INTEGER (LONG | CHAR)
#define NUMBER  (INTEGER | DOUBLE)

typedef struct data {
	TYPE type;
	long LONG;
	double DOUBLE;
	char CHAR;
	char *STRING;
} DATA;


/**
 * @struct Stack
 * \brief Struct de stacks
 * @param size Tamanho máximo do stack
 * @param n_elems Numero de elementos dentro do stack
 */
typedef struct stack{
 DATA *stack;
 int size;
 int n_elems;
}STACK;


//------------------prototipos-----------------------


int has_type(DATA elem, int mask);
STACK *create_stack();

/**
 * \brief Coloca um elemento num stack	
 */
void push(STACK *s, DATA elem);

/**
 * \brief Retira um elemento de um stack
 */
DATA pop(STACK *s);

/**
 * \brief Pega no elemento que está no topo do stack
 * @returns O elemento do topo do stack
 */
DATA top(STACK *s);

/**
 * \brief Verifica se o stack está vazio
 * @returns  
 */
int is_empty(STACK *s);

/**
 * \brief Dá print a um stack
 */
void print_stack(STACK *s);

/**
 * \brief Recebe um elemento e diz de que tipo ele é
 * @returns O tipo do elemento
 */
TYPE tipo(DATA elem);

/**
 * \brief Soma os dois elementos que estão mais acima no stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void SUM(STACK *s);

/**
 * \brief Subtrai o elemento mais acima no stack pelo elemento abaixo desse
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void LESS(STACK *s);

/**
 * \brief Divide o elemento mais acima no stack pelo elemento abaixo desse
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void DIV(STACK *s);

/**
 * \brief Multiplica os dois elementos que estão mais acima no stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void MULT(STACK *s);

/**
 * \brief Coloca o elemento mais acima do stack como base e o elemento abaixo desse como expoente
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void EXP(STACK *s);

/**
 * \brief Calcula o resto da divisão entre o elemento mais acima no stack e o abaixo desse
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void RES(STACK *s);

/**
 * \brief Incrementa um elemento no stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void INC(STACK *s);

/**
 * \brief Decrementa um elemento do stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void DEC(STACK *s);

/**
 * \brief Faz a operação lógica "AND" em bitwise entre os dois elementos mais acima do stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void AND(STACK *s);

/**
 * \brief Faz a operação lógica "OR" em bitwise entre os dois elementos mais acima do stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void OR(STACK *s);

/**
 * \brief Faz a operação lógica "XOR" em bitwise entre os dois elementos mais acima do stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void XOR(STACK *s);

/**
 * \brief Faz a operação lógica "NOT" em bitwise ao elemento no topo do stack
 * @param x O operando da operação
 */
void NOT(STACK *s);

/**
 * \brief Faz a rotação dos 3 elementos mais acima do stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 * @param z Um dos operandos da operação
 */
void ROT(STACK *s);

/**
 * \brief Duplica o elemento mais acima do stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void DUP(STACK *s);

/**
 * \brief Troca os dois elementos mais acima do stack
 * @param x Um dos operandos da operação
 */
void TRD(STACK *s);

/**
 * \brief Retira um elemento do topo do stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void POP1(STACK *s);

/**
 * \brief Converte o topo do stack para inteiro
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void TOINT(STACK *s);

/**
 * \brief Lê uma linha e adiciona-a ao stack
 * @param x Um dos operandos da operação
 * @param y Um dos operandos da operação
 */
void READ(STACK *s);


#define STACK_OPERATION_PROTO(_type, _name)   \
  void push_##_name(STACK *s, _type val);     \
  _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif
