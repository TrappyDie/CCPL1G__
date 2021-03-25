/**
 * @file Contem a função principal do programa
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <assert.h>

/**
 * @def Tamanho usado nos arrays do programa
 */
#define MAX_SIZE	1000

/**
 * \brief Funcao principal do programa
 * @param val Input do utilizador
 * @param token String que contém os operadores
 * @param resto String que contém o que sobra do Input do utilizador
 * @param n Numero que e retirado do Input e inserido no stack 
 * @returns A stack resultante do programa
 */
int main(void) {
    char val[MAX_SIZE];
    char token[MAX_SIZE];
    char resto[MAX_SIZE];
    STACK s = criar_stack();

    assert(fgets(val, MAX_SIZE, stdin) != NULL);
    
    while(sscanf(val, "%s%[^\n]", token, resto) > 0) {
	strcpy(val, resto); 

        *resto = 0;
        long n;
        if (sscanf(token, "%ld", &n) == 1)
        	PUSH (s,n);
        else
		switch (*token) { 
			case '+' : SUM(s); break;
			case '-' : LESS(s); break;
			case '/' : DIV(s); break;
			case '*' : MULT(s); break;
			case '#' : EXP(s); break;
			case '%' : RES(s); break;
			case ')' : INC(s); break;
			case '(' : DEC(s); break;
			case '&' : AND(s); break;
			case '|' : OR(s); break;
			case '^' : XOR(s); break;
			case '~' : NOT(s); break;
    		}
   }
output(s);

return 0;
}
