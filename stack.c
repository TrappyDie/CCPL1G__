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

void print_array(STACK *s) {
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
                print_array( elem.ARRAY );
                    break;       
        }
    }
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
                print_array( elem.ARRAY );
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


void PUTS(STACK *s, STACK *array){
int i;
for(i = 0; i < array->n_elems; i++){
push(s,array->stack[i]);
}
}

void CONCAT(STACK *s){
DATA x = pop(s);
DATA y = pop(s);
if (tipo(x) == ARRAY && tipo(y) == ARRAY) {        
    STACK *arrayx = GET_ARRAY(x);
    STACK *arrayy = GET_ARRAY(y);
    int i;
    for (i = 0; i < arrayx->n_elems; i++){
    push(arrayy, arrayx->stack[i]);
    }
    push_ARRAY(s, arrayy);
    }
if (tipo(x) == ARRAY && tipo(y) != ARRAY) {
    STACK *arrayx = GET_ARRAY(x);
    STACK *newarray = create_stack();
    push(newarray, y);
    for (int i = 0; i < arrayx->n_elems; i++){
        push(newarray, arrayx->stack[i]);
    }
    push_ARRAY(s, newarray);  
    }   
else if (tipo(x) != ARRAY && tipo(y) == ARRAY) {
    STACK *arrayy = GET_ARRAY(y);
    push(arrayy, x);
    push_ARRAY(s, arrayy);        
    }
else if (tipo(x) != ARRAY && tipo(y) != ARRAY) {
    char *stringy = GET_STRING(y);
    char *stringx = GET_STRING(x);
    char string[10000];
    STACK *array = create_stack();
    strcat(stringx, stringy);
    strcpy(string,stringx);
    int f = strlen(string);
    for(int i = 0; i < f; i++){
        push_CHAR(array,string[i]);
    }
    push_ARRAY(s, array);        
    }   
}                   

//  --------------------------------------------------------------------------

void CONCAT2(STACK *s, DATA x, DATA y){
long i = get(x);
STACK *array = GET_ARRAY(y);
STACK *new = create_stack();
 while (i > 0){
     for(int n = 0; n < array->n_elems;n++){
     push(new, array->stack[n]);
     }
  i--;
  }
  push_ARRAY(s , new);
}

//  --------------------------------------------------------------------------

void INDICE(STACK *s, DATA x, DATA y){ 
   STACK *s2 = GET_ARRAY(y);  
   long i = GET_LONG(x);
   if (i > s2->n_elems){
       DATA z2 = s2->stack[s2->n_elems - 1];
       push(s, z2);
   }
  else{
    STACK *s2 = GET_ARRAY(y);
     DATA z2 = s2->stack[i];
     push(s, z2);}
}

//  --------------------------------------------------------------------------

void GETF(STACK *s, DATA x, DATA y){               
long n = get(x);
STACK *array = GET_ARRAY(y);
long m = (array->n_elems) - n;
while ( m != array->n_elems ){
push(s, array->stack[m]);
m++; 
}
}

//  --------------------------------------------------------------------------

void GETI(STACK *s, DATA x, DATA y){
long n = get(x);
STACK *array = GET_ARRAY(y);
long m = 0;
while (m != n){
push(s, array->stack[m]);
m++; 
}
}

//  --------------------------------------------------------------------------

void REMOVEI(STACK *s, DATA x){
  STACK *s1 = GET_ARRAY(x);
  STACK *array = create_stack();
  int i;
  for (i = 1; i <= s1->n_elems; i++){                                   
      push(array, s1->stack[i]); 
  } 
push_ARRAY(s, array); 
push(s, s1->stack[0]);
}

//  --------------------------------------------------------------------------
          
void REMOVEF(STACK *s, DATA x){
  STACK *s1 = GET_ARRAY(x);
  STACK *array = create_stack();
  int i;
  for (i = 0; i < s1->n_elems - 1; i++){                                   
      push(array, s1->stack[i]); 
  } 
  push_ARRAY(s, array);
  push(s, s1->stack[s1->n_elems - 1 ]);     
}       
//  --------------------------------------------------------------------------

void GETSUB(STACK *s, DATA x, DATA y){
STACK *substring = GET_ARRAY(x);
STACK *string = GET_ARRAY(y);
STACK *finalstring = create_stack();
STACK *arraystrings = create_stack();
int i,j = 0,g = 0,m = 0,f = 0;
for(i = 0; i <= string->n_elems; i++){ 
    if (i == string->n_elems) {
        char string2[10000];
        while (m < finalstring->n_elems){
            string2[m] = GET_CHAR(finalstring->stack[m]);
            m++;
            }
            char *strcopia = strdup(string2);
            push_STRING(arraystrings, strcopia);
            }  
    else if (get(string->stack[i]) != get(substring->stack[0]))  {push_CHAR(finalstring, GET_CHAR(string->stack[i]));}
    else {
        g = i;
        while ((get(string->stack[g]) == get(substring->stack[j])) && (j < substring->n_elems)){
            g++;
            j++;            
        }

        if (j == substring->n_elems) {    
            char string2[10000];                                                        
            for (m = 0; m < finalstring->n_elems; m++){                                                              
                string2[m] = GET_CHAR(finalstring->stack[m]);
            }
            char *stringcopia = strdup(string2);
            push_STRING(arraystrings, stringcopia);
            i = g - 1;
            g = 0;
            j = 0;
            m = 0;
            while (finalstring->n_elems > 0){
                pop(finalstring);
            }
            while (string2[f] != '\0'){
                string2[f] = '\0';
                f++;
            }
            f = 0;
}
        else {push(finalstring, string->stack[i]);g = 0;j=0;
    } 
                                             
}
}         
push_ARRAY(s, arraystrings);
}

STACK *FromStoA(char *string){
    char newstring[10000] = {'\0'};
    STACK *array = create_stack();
    int i = 0;
    strcpy(newstring,string);
    while (newstring[i] != '\0'){
        push_CHAR(array,newstring[i]);
        i++;
    }
    return array;
}

void GETINDICE(STACK *s, STACK *substring, STACK *string){   
int i, g, j = 0, r = -1;
    for(i = 0; i < string->n_elems; i++){ 
    if (get(string->stack[i]) != get(substring->stack[0]));
    else {
        g = i;
            while ((get(string->stack[g]) == get(substring->stack[j])) && (j < substring->n_elems)){
                g++;
                j++;            
            }
            if (j == substring->n_elems) {r = i;i = string->n_elems;}

        
    }
}
push_LONG(s,r);
}    


void SUM(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if ((has_type(x, ARRAY)) && (has_type(y, ARRAY))) {push(s,y);push(s,x);CONCAT(s);}
    else if ((tipo(x) == STRING) && (tipo(y) == STRING)) {
        STACK *xs = FromStoA(GET_STRING(x));
        STACK *ys = FromStoA(GET_STRING(y));
        push_ARRAY(s,ys);push_ARRAY(s,xs);CONCAT(s);}
    else if ((tipo(x) == ARRAY) && (tipo(y) == STRING)) {
        STACK *ys = FromStoA(GET_STRING(y));
        push_ARRAY(s,ys);push(s,x);CONCAT(s);}     
    else if ((tipo(x) == STRING) && (tipo(y) == ARRAY)) {
        STACK *xs = FromStoA(GET_STRING(x));
        push(s,y);push_ARRAY(s,xs);CONCAT(s);}
    else if ((has_type(x, ARRAY)) || (has_type(y, ARRAY))) {push(s,y);push(s,x);CONCAT(s);}    
    else if (tipo(x) == LONG && tipo(y) == LONG){
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
    if (tipo(x) == tipo(y) && tipo(x) == ARRAY) GETSUB(s,x,y);
    else if (((GET_LONG(y) / GET_LONG(x)) < 1) && tipo(x) == LONG && tipo(y) == LONG){
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
    if (has_type(y, ARRAY)) CONCAT2(s, x, y);
    else {
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
}
//  --------------------------------------------------------------------------
void EXP(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if ((tipo(x) == STRING) && (tipo(y) == STRING)){
        char *sx = GET_STRING(x);
        char *sy = GET_STRING(y);
        STACK *arrayx = FromStoA(sx);
        STACK *arrayy = FromStoA(sy);
        GETINDICE(s,arrayx, arrayy);
    }
    else if ((tipo(x) == ARRAY) && (tipo(y) == ARRAY)) {GETINDICE(s,GET_ARRAY(x),GET_ARRAY(y));}
    else if (tipo(x) == tipo(y) && tipo(x) == LONG){ 
        long y1 = GET_LONG(y);
        long x1 = GET_LONG(x);
        long ex = pow(y1,x1);
        push_LONG(s,ex);
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
    long y1 = GET_LONG(y);
    long x1 = GET_LONG(x);
    long res = y1 % x1;
    push_LONG(s,res);
}
//  --------------------------------------------------------------------------
void INC(STACK *s){
    DATA x = pop(s);
    if (has_type(x, ARRAY)) REMOVEF(s, x);
    else {
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
} 
//  --------------------------------------------------------------------------
void DEC(STACK *s){
    DATA x = pop(s);
    if (has_type(x, ARRAY)) REMOVEI(s, x); 
    else {
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
}
//  --------------------------------------------------------------------------
void AND(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long y1 = GET_LONG(y);
    long x1 = GET_LONG(x);
    long and = y1 & x1;
    push_LONG(s,and);
}
//  --------------------------------------------------------------------------
void OR(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long y1 = GET_LONG(y);
    long x1 = GET_LONG(x);
    long or = y1 | x1;
    push_LONG(s,or);
}
//  --------------------------------------------------------------------------
void XOR(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long y1 = GET_LONG(y);
    long x1 = GET_LONG(x);
    long xor = y1 ^ x1;
    push_LONG(s,xor);
}
//  --------------------------------------------------------------------------
void NOT(STACK *s){
    DATA x = pop(s);
    if (has_type(x, ARRAY)) PUTS(s, GET_ARRAY(x));
    else if (has_type(x, STRING))
    {
     STACK *arrayx = FromStoA(GET_STRING(x));   
     PUTS(s, arrayx);   
    }
    else {
    long x1 = GET_LONG(x);
    long not = ~x1;
    push_LONG(s,not);}
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
    char line[10000];
    assert(fgets(line, 10000, stdin) != NULL);
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
    else if (tipo(x) == CHAR){
    char c = GET_CHAR(x);
    long n = c;
    push_LONG(s,n);    
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

//  --------------------------------------------------------------------------´

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

//  --------------------------------------------------------------------------

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

char *FromAtoS(STACK *s){
char string2[10000];                                                        
for (int m = 0; m < s->n_elems; m++){                                                              
string2[m] = GET_CHAR(s->stack[m]);
}
char *string = strdup(string2);
return string;
}

//  --------------------------------------------------------------------------

void EQL(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);            
    if (has_type(y, ARRAY) && tipo(x) == LONG) INDICE(s, x, y);
    else if (has_type(y, STRING) && tipo(x) == LONG) {STACK *ys = FromStoA(GET_STRING(y));push_ARRAY(s,ys);push(s,x);DATA x1 = pop(s); DATA y1 = pop(s); INDICE(s, x1, y1);}
    else if (has_type(y, ARRAY) && has_type(x, ARRAY)){
        char *ys = FromAtoS(GET_ARRAY(y));
        char *xs = FromAtoS(GET_ARRAY(x));
        if (strcmp(xs,ys) == 0) push_LONG(s,1);
        else push_LONG(s,0);
    }  
    else {if (get(x) == get(y)) push_LONG(s,1);
          else push_LONG(s,0);
    } 
}
//  --------------------------------------------------------------------------

void LESS(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if ((tipo(y)== ARRAY) && (tipo(x) != ARRAY)) GETI(s, x, y);
    else if ((tipo(y) == ARRAY) && (tipo(x) == ARRAY)) {
        char *ys = FromAtoS(GET_ARRAY(y));
        char *xs = FromAtoS(GET_ARRAY(x));
        if (strcmp(ys,xs) < 0) push_LONG(s,1);
        else push_LONG(s,0);
    }
    else{
    if (get(y) < get(x)) push_LONG(s,1);
    else push_LONG(s,0);
   }
}
//  --------------------------------------------------------------------------


void HIGH(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if ((tipo(y)== ARRAY) && (tipo(x) != ARRAY)) GETF(s, x, y);
    else if ((tipo(y) == ARRAY) && (tipo(x) == ARRAY)) {
        char *ys = FromAtoS(GET_ARRAY(y));
        char *xs = FromAtoS(GET_ARRAY(x));
        if (strcmp(ys,xs) > 0) push_LONG(s,1);
        else push_LONG(s,0);
    }    
    else{
    if (get(y) > get(x)) push_LONG(s,1);
    else push_LONG(s,0);
    }
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
    if ((tipo(x) == ARRAY) && (tipo(y) == ARRAY)) {
        char *ys = FromAtoS(GET_ARRAY(y));
        char *xs = FromAtoS(GET_ARRAY(x));
        if (strcmp(ys,xs) < 0) push_STRING(s,ys);
        else push_STRING(s,xs);
    }
    else if (get(x) < get(y)) push(s,x);
    else push(s,y); 
}
//  --------------------------------------------------------------------------
void PUTMAI(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if ((tipo(x) == ARRAY) && (tipo(y) == ARRAY)) {
        char *ys = FromAtoS(GET_ARRAY(y));
        char *xs = FromAtoS(GET_ARRAY(x));
        if (strcmp(ys,xs) > 0) push_STRING(s,ys);
        else push_STRING(s,xs);
    }    
    else if (get(x) > get(y)) push(s,x);
    else push(s,y); 
}
//  --------------------------------------------------------------------------
void IF(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);  
    DATA z = pop(s);
    if (tipo(z) == ARRAY) {
        STACK *array = GET_ARRAY(z);
        if (array->n_elems != 0) push(s,y);
        else push(s,x);
    }  
    else { if (get(z) != 0) push(s,y);
            else push(s,x);}
}   

//  --------------------------------------------------------------------------

char *get_delimited(char *val, char *token, char *resto){
if (*token == '[')    sscanf(val, "%[^]]%[^\n]]", token, resto);
if (*token == '\"')   {token++;}
    resto++;
return token; 
}

//  --------------------------------------------------------------------------

void STRINGET(STACK *s, char *token, char *resto, char *val){
    char string[10000];
    char tokenend[10000] = {'\0'};
    int i = 0, f = 0;
    char j = 0;
    STACK *array = create_stack();
    while (j != '\"'){
        strcpy(string, token);
        if (string[strlen(string) - 1] == '\"') {
            j = '\"';
            string[strlen(string) - 1] = '\0';
            strcat(tokenend,string);
            for (i = 0; tokenend[i] != '\0'; i++){
                push_CHAR(array, tokenend[i]);
            }
        }
        else if (string[strlen(string) - 1] != '\"') {
            strcat(tokenend, string);
            strcat(tokenend, " ");
            strcpy(val, resto);
            while (resto[f] != '\0'){
                resto[f] = '\0';
                f++;
            }
            f = 0;
            sscanf(val, "%s%[^\n]", token, resto);
            j = 0; 
        }    
}
push_ARRAY(s, array); 
}

//  --------------------------------------------------------------------------
void SIZENUMBER(STACK *s, DATA x){
   if (tipo(x) == LONG){
   STACK *array = create_stack();
   long y = GET_LONG(x);
   long i = 0;
   while (i != y) {
     push_LONG(array,i);
     i++;
     }
     push_ARRAY(s, array);
   }
  else if (tipo(x) == DOUBLE){
   STACK *array = create_stack();
   double y = GET_DOUBLE(x);
   long i = 0;
   while (i != y) {
     push_DOUBLE(array,i);
     i++;
     }
     push_ARRAY(s, array);
   }

}

//  --------------------------------------------------------------------------

void SIZE(STACK *s){
   DATA x = pop(s);
   if(tipo(x) == STRING) {
    char *str = GET_STRING(x);
    STACK *s1 = FromStoA(str);
    push_LONG(s, s1->n_elems);}
   else if (tipo(x) == ARRAY){
    STACK *s2 = GET_ARRAY(x); 
    push_LONG(s, s2->n_elems);
   }
   else SIZENUMBER(s, x);
}

//  --------------------------------------------------------------------------

void READ2(STACK *s){
    char line[10000];
    char lineend[10000];
    STACK *lastread = create_stack();
    char *line3 = strdup(line);     
    while (strlen(line) != 1){        
        assert(fgets(line, 10000, stdin) != NULL);
        char *line2 = strdup(line);
        strcat(line3,line2);
    }
    line3[strlen(line3) - 1] = '\0';
    strcpy(lineend, line3);
    int f = strlen(lineend);
    for(int i = 0; i < f; i++){
        push_CHAR(lastread,lineend[i]);
    }
    push_ARRAY(s, lastread);  
}

//  --------------------------------------------------------------------------

void WHITE(STACK *s){
    DATA x = pop(s);
    STACK *arrayinit;
    char stringtemp[10000] = {'\0'};
    char *stringend = "\0";
    int i = 0, n = 0, f = 0;
    if (tipo(x) == STRING) (arrayinit = FromStoA(GET_STRING(x)));
    else{
    arrayinit = GET_ARRAY(x); }
    STACK *arrayend = create_stack();
    while (i < arrayinit->n_elems){
        while (((GET_CHAR(arrayinit->stack[i]) != ' ') && (i < arrayinit->n_elems)) && (GET_CHAR(arrayinit->stack[i]) != '\n')) {
            stringtemp[n] = GET_CHAR(arrayinit->stack[i]);
            i++;
            n++;
        }
            stringend = strdup(stringtemp);                                     
            push_STRING(arrayend, stringend);
            while (stringtemp[f] != '\0'){
                stringtemp[f] = '\0';
                f++;
            }
            i++;
            f = 0;           
            n = 0;
    }
push_ARRAY(s, arrayend);
}

//  --------------------------------------------------------------------------

void NEW(STACK *s){
    DATA x = pop(s);
    char stringtemp[10000] = {'\0'};
    char *stringend = "\0";
    int i = 0, n = 0, f = 0;
    STACK *arrayinit = GET_ARRAY(x); 
    STACK *arrayend = create_stack();
    while (i < arrayinit->n_elems){
        while ((GET_CHAR(arrayinit->stack[i]) != '\n') && (i < arrayinit->n_elems)) {
            stringtemp[n] = GET_CHAR(arrayinit->stack[i]);
            i++;
            n++;
        }
            stringend = strdup(stringtemp);                                     
            push_STRING(arrayend, stringend);
            while (stringtemp[f] != '\0'){
                stringtemp[f] = '\0';
                f++;
            }
            i++;
            f = 0;           
            n = 0;
    }
push_ARRAY(s, arrayend);
}
//  --------------------------------------------------------------------------

/**
* \brief Define que faz as funções de push e pop usadas para cada tipo nos stacks
*/
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