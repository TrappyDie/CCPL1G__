#include <stdio.h>
#include <string.h>
#include "stack.h"

#define MAX_SIZE	1000

int main(void) {
    char val[MAX_SIZE];
    char token[MAX_SIZE];
    char resto[MAX_SIZE];
    long n;
    STACK s = criar_stack();

    fgets(val, MAX_SIZE, stdin);
    while(sscanf(val, "%s%[^\n]", token, resto) > 0) {
	strcpy(val, resto); 

        *resto = 0;
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
			case '(' : INC(s); break;
			case ')' : DEC(s); break;
			case '&' : AND(s); break;
			case '|' : OR(s); break;
			case '^' : XOR(s); break;
			case '~' : NOT(s); break;
    		}
   }
output(s);

return 0;
}