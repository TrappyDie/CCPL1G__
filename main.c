#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(void) {
    char val[100];
    char token[100];
    char resto[100];
    long n;
    char c[100];
    int i = 0;
    STACK s1 = criar_stack();
    STACK s2 = criar_stack();

    fgets(val, 100, stdin);
    while(sscanf(val, "%s%[^\n]", token, resto) > 0) {
        *resto = 0;
        if (sscanf(token, "%ld", &n) == 1)
        	PUSH (s1,n);
        else
            (c[i] = token[0]);
            i++;
   }
    
    c[i] = '\0';
    for(int x = strlen(c); x >= 0; x--){
    	PUSH(s2,c[x]);
    }
    switch ('+') {
    	case '+' : SUM(s1); break;
    	case '-' : LESS(s1); break;
    	case '/' : DIV(s1); break;
    	case '*' : MULT(s1); break;
    	case '#' : EXP(s1); break;
    	case '%' : RES(s1); break;
    	case '(' : INC(s1); break;
    	case ')' : DEC(s1); break;
    	case '&' : AND(s1); break;
    	case '|' : OR(s1); break;
    	case '^' : XOR(s1); break;
    	case '~' : NOT(s1); break;
    }

    return 0;
}
