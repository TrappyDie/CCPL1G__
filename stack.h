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
/**
 * @def Foi definido o tipo INTEGER como LONG ou CHAR 
 */
#define INTEGER (LONG | CHAR)
/**
 * @def Foi definido o tipo NUMBER como INTEGER ou DOUBLE
 */
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

/**
 * \brief Verifica se um elemento tem certo tipo
 */
int has_type(DATA elem, int mask);

/**
 * \brief Função que inicializa um stack
 */
STACK *create_stack();
/**
 * \brief Coloca um elemento num stack	
 */
void push(STACK *s, DATA elem);
/**
 * \brief Retira um elemento de um stack
 */
DATA pop(STACK *s);
