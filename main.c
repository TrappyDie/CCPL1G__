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

    fgets(val, 100, stdin);
    while(sscanf(val, "%s%[^\n]", token, resto) > 0) {
        *resto = 0;
        if(sscanf(token, "%ld", &n) == 1)
        else
            (c[i] = token[0]) && i++;
        c[i] = '\0';
    }
    return 0;
}
