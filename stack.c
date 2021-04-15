/**
 * @file Contém as funções relacionadas com o stack
 */



//  ---------------------------------------------------------
//  Stack.c Function Library
//  Version 1.0 - Beta
//  Revision 1.52
//  Project LAUM2021 CCPL1G03
//  ---------------------------------------------------------
//  ----------------------- Libraries -----------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"
//  ----------------------- Libraries -----------------------
//  --------------------- Code Begining ---------------------

int has_type(DATA elem, int mask){
    return (elem.type & mask) != 0;
}

STACK *create_stack() {
    STACK *s = (STACK *) calloc(1, sizeof(STACK));
    s->size = 100;
    s->stack = (DATA *) calloc(s->size, sizeof(DATA));
    return s;
}

void push(STACK *s, DATA elem) {
    if (s->size == s->n_elems) {
        s->size += 100;
        s->stack = (DATA *) realloc(s->stack,s->size * sizeof(DATA));
   }
    s->stack[s->n_elems] = elem;
    s->n_elems++;
}

DATA pop(STACK *s) {
    s->n_elems--;
    return s->stack[s->n_elems];
}

DATA top(STACK *s) {
    return s->stack[s->n_elems - 1];
}

int is_empty(STACK *s){
    return s->n_elems == 0;
}

void print_stack(STACK *s) {
    for(int k = 0; k < s->n_elems; k++) {
        DATA elem = s->stack[k];
        TYPE type = elem.type;
        switch(type) {
            case LONG:
                printf("%ld", elem.LONG);
                break;
            case DOUBLE:
                printf("%.6g", elem.DOUBLE);
                break;
            case CHAR:
                printf("%c", elem.CHAR);
                break;
            case STRING:
                printf("%s", elem.STRING);
                break;
        }
    }
    printf("\n");
}

TYPE tipo(DATA elem){
return elem.type;
}

double GET_DOUBLE(DATA elem){
switch(elem.type) {
    case LONG:
        return elem.LONG;
        break;
    case CHAR:
        return elem.CHAR;
        break;
    case DOUBLE:
        return elem.DOUBLE;
        break;
    case STRING:
        return 0;
        break;
    }
return 0;
}

long GET_LONG(DATA elem){
switch(elem.type) {
    case LONG:
    return elem.LONG;
        break;
    case CHAR:
    return elem.CHAR;
        break;
    case DOUBLE:
    return elem.DOUBLE;
        break;
    case STRING:
    return 0;
        break;
    }
return 0;
}

