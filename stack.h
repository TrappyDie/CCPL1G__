/**
 * @file Contém as structs uzadas pelo programa 
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
/** Define o TYPE usado na struct data, atribuindo valores aos tipos */
typedef enum {
    /** inteiro */
    LONG = 1,
    /** real */
    DOUBLE = 2,
    /** caracteres */
    CHAR = 4,
    /** lista de caracteres */
    STRING = 8,
    /** array */
    ARRAY = 16} TYPE;
//  --------------------------------------------------------------------------
/**
 * @def INTEGER
 * Foi definido o tipo INTEGER como LONG ou CHAR 
 */
#define INTEGER (LONG | CHAR)
/**
 * @def NUMBER
 * Foi definido o tipo NUMBER como INTEGER ou DOUBLE
 */
#define NUMBER  (INTEGER | DOUBLE)
//  --------------------------------------------------------------------------
/** Struct stack */
struct stack;
/** Struct que define tipos*/                                                                                                          
typedef struct data {
/** Tipo correspondente a TYPE */
	TYPE type;
/** Tipo correspondente a long */	
	long LONG;                          
/** Tipo correspondente a double */	
	double DOUBLE;
/** Tipo correspondente a char */	
	char CHAR;
/** Tipo correspondente a string */ 	 
	char *STRING;
/** Tipo correspondente a array */
/** Stack onde se vai ter os arrays */  	
	struct stack *ARRAY;	
} DATA;
//  --------------------------------------------------------------------------
/** Struct de stacks */
typedef struct stack{
/** Pointer onde temos um elemento do stack */
    DATA *stack;
/** Inteiro com o tamanho do stack */ 
    int size;
/** Inteiro com o numero de elementos que estão no stack */    
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

/**
 * \brief Pega no elemento que está no topo do stack
 * @returns O elemento do topo do stack
 */
DATA top(STACK *s);

/**
 * \brief Verifica se o stack está vazio 
 */
int is_empty(STACK *s);

/**
 * \brief Dá print a um stack
 */
void print_stack(STACK *s);

/**
 * \brief Dá print a um array
 */
void print_array(STACK *s);

/**
 * \brief Recebe um elemento DOUBLE e devolve o elemento
 */
double GET_DOUBLE(DATA elem);
/**
 * \brief Recebe um elemento LONG e devolve o elemento
 */
long GET_LONG(DATA elem);
/**
 * \brief Recebe um elemento CHAR e devolve o elemento
 */
char GET_CHAR(DATA elem);
/**
 * \brief Recebe um elemento STRING e devolve o elemento
 */
char *GET_STRING(DATA elem);

/**
 * \brief Recebe um elemento ARRAY e devolve o elemento
 */
STACK *GET_ARRAY(DATA elem);

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
 * \brief Recebe um elemento DATA e retorna o elemento no tipo double
 */
double get(DATA x);
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
void READ(STACK *s);

/**
 * \brief Coloca no stack o tamanho do array
 * @param s1 Stack onde está o array
 * @param x Array retirado do stack
 */
void SIZE(STACK *s);

/**
 * \brief Coloca todos os numeros de 0 até ao long/ double (x - 1)
 * @param s1 array onde se vão colocar os valores
 * @param x Long ou Double retirado do stack
 * @param i Long usado na condição do while
 */
void SIZENUMBER(STACK *s, DATA x);
/**
 * \brief Coloca os elementos do array no stack
 * @param i Int usado para aceder a elementos especificos do stack
 */
void PUTS(STACK *s, STACK *array);

/**
 * \brief Separa os elementos do array/string do resto do input
 */
char *get_delimited(char *val, char *token, char *resto);

/**
 * \brief Vai buscar o elemento de indice n a um array
 */
void INDICE(STACK *s, DATA x, DATA y);
/**
 * \brief Concatena 2 elementos de um stack
 */
void CONCAT(STACK *s);

/**
 * \brief Concatena multiplas vezes um array
 * @param array Stack com o array que se vai concatenar
 * @param i Numero de vezes que se vai ter o array
 * @param x Valor recebido pela função
 * @param y Valor recebido na função
 * @param s Stack onde sera colocado o resultado
*/
void CONCAT2(STACK *s, DATA x, DATA y);

/**
 * \brief Vai ao array e devolve os seus elementos desde o inicio até ao elemento indice x
 */
void GETI(STACK *s, DATA x, DATA y);
 
/**
* \brief Vai ao array e devolve os seus elementos desde o final até ao elemento indice x
*/
void GETF(STACK *s, DATA x, DATA y);

/**
 * \brief Remove o elemento do inicio do array e coloca no stack depois do array
 */

void REMOVEI(STACK *s, DATA x);

/**
 * \brief Remove o elemento do final do array e coloca no stack depois do array
 */


void REMOVEF(STACK *s, DATA x);

/**
 * \brief Função que recebe um string e o coloca no stack
 * @param s Stack onde se vão colocar a string
 * @param token String do input
 * @param resto O que vai sobrar do string do input 
 */
void STRINGET(STACK *s, char *token, char *resto, char *val);

/**
 * \brief Recebe um string e um delimitador e separa a string colocando cada parte desta num array
 * @param s Stack onde se vai colocar o array final
 * @param x Delimitadores
 * @param y String que vai ser delimitada
 */ 
void GETSUB(STACK *s, DATA x, DATA y);

/**
 * \brief Recebe uma string e um substring e encontra o indice em que começa esse substring na string
 * @param s Stack onde se vai colocar o indice
 * @param x Substring
 * @param y String
 */ 
void GETINDICE(STACK *s, STACK *arrayx, STACK *arrayy);

/**
 * \brief Lê todo o input e coloca-o numa string
 * @param s Stack onde vai colocar o string
 */ 
void READ2(STACK *s);
/**
 * \brief Separa um string pelos seus espaços e coloca-o separado num array
 * @param s Stack onde se vai colocar o array
 */ 
void WHITE(STACK *s);

/**
 * \brief Recebe um stack array e coloca-o numa string
 * @param s Stack que vai ser transformado
 */ 
char *FromAtoS(STACK *s);

/**
 * \brief Recebe um string e coloca-o num array
 * @param string String que vai ser tranformado
 */ 
STACK *FromStoA(char *string);

/**
 * \brief Separa um string pelos seus newlines e coloca-o separado num array
 * @param s Stack onde se vai colocar o array
 */ 
void NEW(STACK *s);

/**
* \brief Define que faz as funções de push e pop usadas para cada tipo nos stacks
*/
#define STACK_OPERATION_PROTO(_type, _name)   \
  void push_##_name(STACK *s, _type val);     \
  _type pop_##_name(STACK *s);
  
  
STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)
STACK_OPERATION_PROTO(struct stack *, ARRAY)

#endif
//---------------------- Code Ending ----------------------