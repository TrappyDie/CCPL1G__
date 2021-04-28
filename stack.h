/**
 * @file Função onde está definido o stack 
 */
//  ---------------------------------------------------------
//  Stack.h - Stack Function Library
//  Version 1.0 - Beta
//  Revision 1.02
//  Project LAUM2021 CCPL1G03
//  ---------------------------------------------------------
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
//  ----------------------- Libraries -----------------------
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//  ----------------------- Libraries -----------------------
//  --------------------- Code Begining ---------------------
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;
//  ------------------------Defines--------------------------
#define INTEGER (LONG | CHAR)
#define NUMBER  (INTEGER | DOUBLE)
//  --------------------------------------------------------------------------
/**
 * @struct Data
 * \brief Struct que define tipos
 * @param LONG Tipo correspondente a long
 * @param DOUBLE Tipo correspondente a double
 * @param CHAR Tipo correspondente a char
 * @param *STRING Tipo correspondente a string 
 */
typedef struct data {
	TYPE type;
	long LONG;
	double DOUBLE;
	char CHAR;
	char *STRING;
} DATA;
//  --------------------------------------------------------------------------
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
//  --------------------------------------------------------------------------
//  ---------------------------- prototipos ----------------------------------
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
void MINUS(STACK *s);

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
double POP1(STACK *s);

/**
 * \brief Converte o topo do stack para inteiro
 * @param x O elemento da stack que vai ser convertido
 */
void TOINT(STACK *s);

/**
 * \brief Converte o topo do stack para double 
 * @param x O elemento da stack que vai ser convertido
 */
void TODOB(STACK *s);

/**
 * \brief Converte o topo do stack para char
 * @param x O elemento da stack que vai ser convertido
 */
void TOCHAR(STACK *s);

/**
 * \brief Copia n-ésimo elemento para o topo do stack
 * @param x A posição do elemento que vai ser copiado
 * @param y O elemento que vai ser copiado
 */
void CHANGE(STACK *s);

/**
 * \brief Compara dois elementos, se a comparação (igual) for verdadeira devolve 1 e se for falsa devolve 0
 * @param x Um dos elementos que se vai comparar
 * @param y Um dos elementos que se vai comparar
 */
void EQL(STACK *s);

/**
 * \brief Compara dois elementos, se a comparação (menor) for verdadeira devolve 1 e se for falsa devolve 0
 * @param x Um dos elementos que se vai comparar
 * @param y Um dos elementos que se vai comparar
 */
void LESS(STACK *s);

/**
 * \brief Compara dois elementos, se a comparação (maior) for verdadeira devolve 1 e se for falsa devolve 0
 * @param x Um dos elementos que se vai comparar                                                                      
 * @param y Um dos elementos que se vai comparar
 */
void HIGH(STACK *s);

/**
 * \brief Troca o valor lógico de um elemento, caso este for diferente de 0 torna-se igual a 0, caso seja igual a 0 torna-se igual a 1
 * @param x elemento que se vai negar
 */
void NAO(STACK *s);

/**
 * \brief Compara dois elementos, se a comparação (&) for verdadeira devolve um numero diferente de 0 e se for falsa devolve 0
 * @param x Um dos elementos que se vai comparar
 * @param y Um dos elementos que se vai comparar
 */
void AND2(STACK *s); 

/**
 * \brief Compara dois elementos, se a comparação (|) for verdadeira devolve um numero diferente de 0 e se for falsa devolve 0
 * @param x Um dos elementos que se vai comparar
 * @param y Um dos elementos que se vai comparar
 */
void OR2(STACK *s);

/**
 * \brief Compara dois elementos, se a comparação (<) for verdadeira devolve um numero diferente de 0 e se for falsa devolve 0
 * @param x Um dos elementos que se vai comparar
 * @param y Um dos elementos que se vai comparar
 */
void PUTMEN(STACK *s);

/**
 * \brief Compara dois elementos, se a comparação (>) for verdadeira devolve um numero diferente de 0 e se for falsa devolve 0
 * @param x Um dos elementos que se vai comparar
 * @param y Um dos elementos que se vai comparar
 */
void PUTMAI(STACK *s);

/**
 * \brief Compara três elementos, se a comparação (IF) for verdadeira devolve o segundo elemento e se for falsa devolve o terceiro elemento
 * @param x Um dos elementos que se vai comparar
 * @param y Um dos elementos que se vai comparar
 * @param z Um dos elementos que se vai comparar
 */
void IF(STACK *s);

/**
 * \brief Coloca no stack um elemento guardado numa variável
 * @param c Char recebido do input
 * @param i Valor ASCII do c
 * @param vars Array onde estão guardadas as variáveis
 * @param N Variável onde está guardado um char
 * @param S Variável onde está guardado um char
 */
void READ(STACK*s);


/**
 * @def prototipo das funções relacionadas com stacks
 */

#define STACK_OPERATION_PROTO(_type, _name)   \
  void push_##_name(STACK *s, _type val);     \
  _type pop_##_name(STACK *s);
  
  
STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)


#endif
//---------------------- Code Ending ----------------------
