/**
 * @file Contém as funções relacionadas com o stack
 */



//  ---------------------------------------------------------
//  Stack.c - Function Library
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


//  --------------------------------------------------------------------------
int has_type(DATA elem, int mask){
    return (elem.type & mask) != 0;
}
//  --------------------------------------------------------------------------
STACK *create_stack() {	
    STACK *s = (STACK *) calloc(1, sizeof(STACK));
    s->size = 100;
    s->stack = (DATA *) calloc(s->size, sizeof(DATA));
    return s;
}
//  --------------------------------------------------------------------------
void push(STACK *s, DATA elem) {
    if (s->size == s->n_elems) {
        s->size += 100;
        s->stack = (DATA *) realloc(s->stack,s->size * sizeof(DATA));
    }
    s->stack[s->n_elems] = elem;
    s->n_elems++;
}
//  --------------------------------------------------------------------------
DATA pop(STACK *s) {
    s->n_elems--;
    return s->stack[s->n_elems];
}
//  --------------------------------------------------------------------------
DATA top(STACK *s) {
    return s->stack[s->n_elems - 1];
}
//  --------------------------------------------------------------------------
int is_empty(STACK *s){
    return s->n_elems == 0;
}
//  --------------------------------------------------------------------------
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
            case ARRAY:
                break;       
        }
    }
    printf("\n");
}
//  --------------------------------------------------------------------------
TYPE tipo(DATA elem){
return elem.type;
}
//  --------------------------------------------------------------------------
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
         case ARRAY:
            return 0;
                break;         
    }
return 0;
}
//  --------------------------------------------------------------------------
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
        case ARRAY:
           return 0;
               break;
    }
return 0;
}
//  --------------------------------------------------------------------------
char GET_CHAR(DATA elem){
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
        case ARRAY:
            return 0;
                break;
    }
return 0;
}
//  --------------------------------------------------------------------------
char *GET_STRING(DATA elem){
    switch(elem.type) {
        case LONG:
            return 0;
                break;
        case CHAR:
            return 0;
                break;
        case DOUBLE:
            return 0;
                break;
        case STRING:
            return elem.STRING;
                break;
        case ARRAY:
            return 0;
                break;        
    }
return 0;
}

//  --------------------------------------------------------------------------

STACK *GET_ARRAY(DATA elem){
     switch(elem.type){
        case LONG:
            return 0;
                break;
        case CHAR:
            return 0;
                break;
        case DOUBLE:
            return 0;
                break;
        case STRING:
            return 0;
                break;
        case ARRAY:
            return elem.ARRAY;
                break;        
    }
return 0;
}    



void SUM(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (tipo(x) == LONG && tipo(y) == LONG){
        push_LONG(s,GET_LONG(x) + GET_LONG(y));
    }
    else if (tipo(x) == DOUBLE && tipo(y) == DOUBLE){
        push_DOUBLE(s,GET_DOUBLE(x) + GET_DOUBLE(y));
    }
    else if (tipo(x) == LONG && tipo(y) == DOUBLE){
        push_DOUBLE(s,GET_LONG(x) + GET_DOUBLE(y));
    }
    else{
        push_DOUBLE(s,GET_DOUBLE(x) + GET_LONG(y));
    }
}
//  --------------------------------------------------------------------------
void MINUS(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (tipo(x) == LONG && tipo(y) == LONG){
        push_LONG(s,GET_LONG(y) - GET_LONG(x));
    }
    else if (tipo(x) == DOUBLE && tipo(y) == DOUBLE){
        push_DOUBLE(s,GET_DOUBLE(y) - GET_DOUBLE(x));
    }
    else if (tipo(x) == LONG && tipo(y) == DOUBLE){
        push_DOUBLE(s,GET_LONG(x) - GET_DOUBLE(y));
    }
    else {
        push_DOUBLE(s,GET_DOUBLE(x) - GET_LONG(y));
    }
}
//  --------------------------------------------------------------------------
void DIV(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (((GET_LONG(y) / GET_LONG(x)) < 1) && tipo(x) == LONG && tipo(y) == LONG){
        push_LONG(s,0);
    }
    else if (tipo(y) == LONG && tipo(x) == LONG){
        push_LONG(s,GET_LONG(y) / GET_LONG(x));
    }
    else{
        push_DOUBLE(s,GET_DOUBLE(y) / GET_DOUBLE(x));
    }
}
//  --------------------------------------------------------------------------
void MULT(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (tipo(x) == tipo(y) && tipo(x) == LONG){
        push_LONG(s,GET_LONG(x) * GET_LONG(y));
    }
    else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE){
        push_LONG(s,GET_DOUBLE(x) * GET_DOUBLE(y));
    }
    else if (tipo(x) == LONG && tipo(x) == DOUBLE){
        push_LONG(s,GET_LONG(x) * GET_DOUBLE(y));
    }
    else {
        push_LONG(s,GET_DOUBLE(x) * GET_LONG(y));
    }
}
//  --------------------------------------------------------------------------
void EXP(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (tipo(x) == tipo(y) && tipo(x) == LONG){ 
        push_LONG(s,pow(GET_LONG(y), GET_LONG(x)));
    }    
    else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE){
        float y1 = GET_DOUBLE(y);
        float x1 = GET_DOUBLE(x);
        float ex = pow(y1,x1);
        push_DOUBLE(s, ex);
    }    
    else if (tipo(x) != tipo(y) && tipo(x) == LONG){
        float y1 = GET_DOUBLE(y);
        float x1 = GET_LONG(x);
        float ex = pow(y1,x1);
        push_DOUBLE(s, ex);
    }    
    else if (tipo(x) != tipo(y) && tipo(x) == DOUBLE){
        float y1 = GET_LONG(y);
        float x1 = GET_DOUBLE(x);
        float ex = pow(y1,x1);
        push_DOUBLE(s, ex);
    }
}
//  --------------------------------------------------------------------------
void RES(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    push_LONG(s,GET_LONG(y) % GET_LONG(x));
}
//  --------------------------------------------------------------------------
void INC(STACK *s){
    DATA x = pop(s);
    if  (tipo(x) == LONG){
        long x1 = GET_LONG(x);
        x1++;
        push_LONG(s,x1);
    }
    else if (tipo(x) == DOUBLE){
         double x2 = GET_DOUBLE(x);
         x2++;
        push_DOUBLE(s,x2);
    }
    else if (tipo(x) == CHAR) {
         char x3 = GET_CHAR(x);
         x3++;
         push_CHAR(s,x3);
    }
}
//  --------------------------------------------------------------------------
void DEC(STACK *s){
    DATA x = pop(s);
    if  (tipo(x) == LONG){
        long x1 = GET_LONG(x);
        x1--;
        push_LONG(s,x1);
    }
    else if (tipo(x) == DOUBLE){
        double x2 = GET_DOUBLE(x);
        x2--;
        push_DOUBLE(s,x2);
    }
    else if (tipo(x) == CHAR){
        char x3 = GET_CHAR(x);
        x3--;
        push_CHAR(s,x3);
    }
}
//  --------------------------------------------------------------------------
void AND(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    push_LONG(s,GET_LONG(y) & GET_LONG(x));
}
//  --------------------------------------------------------------------------
void OR(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    push_LONG(s,GET_LONG(y) | GET_LONG(x));
}
//  --------------------------------------------------------------------------
void XOR(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    push_LONG(s,GET_LONG(y) ^ GET_LONG(x));
}
//  --------------------------------------------------------------------------
void NOT(STACK *s){
    DATA x = pop(s);
    push_LONG(s,~GET_LONG(x));
}
//  --------------------------------------------------------------------------
void ROT(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    DATA z = pop(s);
	push(s,y);
	push(s,x);
	push(s,z);
}
//  --------------------------------------------------------------------------
void DUP(STACK *s){
    DATA x = pop(s);
    if (tipo(x) == CHAR){ 
    	push_CHAR(s, GET_CHAR(x));
    	push_CHAR(s, GET_CHAR(x));
    }
    else {
        push(s,x);
        push(s,x);
    }
}    
//  --------------------------------------------------------------------------
void TRD(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    push(s,x);
    push(s,y);
}

//  --------------------------------------------------------------------------
double POP1(STACK *s){
    pop(s);
    return 0;
}

//  --------------------------------------------------------------------------
void READ(STACK *s){
    char line[1000];
    assert(fgets(line, 100, stdin) != NULL);
    char *line2 = strdup(line);
    push_STRING(s,line2);   
}
//  --------------------------------------------------------------------------
void TOINT(STACK *s){
    DATA x =  pop(s);
    if (tipo(x) == LONG){
    push(s,x);    
    }
    else if (tipo(x) == DOUBLE){
    push_LONG(s, GET_DOUBLE(x));                                        
    }
    else if (tipo(x) == STRING){
    char *c = GET_STRING(x);
    int n = atoi(c);
    push_LONG(s,n);
   }
}
//  --------------------------------------------------------------------------
void TODOB(STACK *s){
    DATA x =  pop(s);
    if (tipo(x) == LONG){
    push_DOUBLE(s, GET_DOUBLE(x));   
    }
    else if (tipo(x) == DOUBLE){
    push(s,x);                                      
    }
    else if (tipo(x) == STRING){
    float n = atof(GET_STRING(x));
    push_DOUBLE(s,n);					
    }
}
//  --------------------------------------------------------------------------
void TOCHAR(STACK *s){
    DATA x = pop(s);
    char c;
    if (tipo (x) == LONG){
        c = (char) (GET_LONG(x));
    }
    else{
        c =  (char) (GET_DOUBLE(x));
    }
    push_CHAR(s,c);
} 
//  --------------------------------------------------------------------------
void CHANGE( STACK *s){
    DATA x = pop(s);
    DATA y = s->stack[s->n_elems - GET_LONG(x) - 1];
    push(s, y);
}


double get(DATA x){
 switch(x.type) {
        case LONG:
            return GET_LONG(x);
                break;
        case CHAR:
            return GET_CHAR(x);
                break;
        case DOUBLE:
            return GET_DOUBLE(x);
                break;
        case STRING:
            return 0;
                break;
        case ARRAY:
            return 0;
                break;               
       }
return 0;      
}          
            
//  --------------------------------------------------------------------------
void EQL(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (get(x) == get(y)) push_LONG(s,1);
    else push_LONG(s,0); 
}
//  --------------------------------------------------------------------------

void LESS(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (get(y) < get(x)) push_LONG(s,1);
    else push_LONG(s,0);
}

//  --------------------------------------------------------------------------


void HIGH(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (get(y) > get(x)) push_LONG(s,1);
    else push_LONG(s,0);
}

//  --------------------------------------------------------------------------
void NAO(STACK *s){
    DATA x = pop(s);
    if (get(x) == 0) push_LONG(s,1);
    else push_LONG(s,0);
              
}
//  -------------------------------------------------------------------------- 
 void AND2(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if(get(x) != 0 && get(y)!=0 && get(x)>get(y)){
            push(s,x);
        }
        else if(get(x)!= 0 && get(y)!=0 && get(x)<get(y)){
            push(s,y);
        }
        else push_LONG(s,0); 
}
//  --------------------------------------------------------------------------

void OR2(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if(get(x) == 0 && get(y)==0){
            push_LONG(s,0);
        }
        else if(get(y) == 0){
            push(s,x);
        }
        else if(get(x) == 0){
            push(s,y);
        }
        else if(get(x) > get(y)){
            push(s,x);
        }
        else push(s,y); 
}
//  --------------------------------------------------------------------------
void PUTMEN(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (get(x) < get(y)) push(s,x);
    else push(s,y); 
}
//  --------------------------------------------------------------------------
void PUTMAI(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if (get(x) > get(y)) push(s,x);
    else push(s,y); 
}
//  --------------------------------------------------------------------------
void IF(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);  
    DATA z = pop(s);  
    if (get(z) != 0) push(s,y);
    else push(s,x);
}   


/*

void PUTS(STACK *s){
   int i = 0;
   while (array->n_elems != i){
       DATA x = array->stack[i];
       push(s,x);
       i++;
       }

} 
*/

char *get_delimited(char *val, char *token, char *resto){
sscanf(val, "%[^]]%s", token, resto);
return token;
}

void SIZE(STACK *s){
   DATA x = pop(s);
   if (tipo(x) == ARRAY){
   STACK *s1 = GET_ARRAY(x); 
   push_LONG(s, s1->n_elems);
   }
}

          
       
      
//  --------------------------------------------------------------------------
#define STACK_OPERATION(_type,_name)\
    void push_##_name(STACK *s,_type val) {\
        DATA elem;\
        elem.type = _name;\
        elem._name = val;\
        push(s, elem);\
    }\
    _type pop_##_name(STACK *s) {\
        DATA elem = pop(s);\
        return elem._name;\
    }
//  --------------------------------------------------------------------------
STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
STACK_OPERATION(struct stack *, ARRAY)
//  --------------------------------------------------------------------------
//---------------------- Code Ending ----------------------
