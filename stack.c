#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

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
	s-> n_elems--;
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
			printf("%ld", elem.LONG); break;
			case DOUBLE:
			printf("%.1lf", elem.DOUBLE); break;
			case CHAR:
			printf("%c", elem.CHAR); break;
			case STRING:
			printf("%s", elem.STRING); break;
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
	return elem.LONG; break;
	case CHAR:
	return elem.CHAR; break;
	case DOUBLE:
	return elem.DOUBLE; break;
	case STRING:
	return 0; break;
	}
return 0;
}

long GET_LONG(DATA elem){
switch(elem.type) {
	case LONG:
	return elem.LONG; break;
	case CHAR:
	return elem.CHAR; break;
	case DOUBLE:
	return elem.DOUBLE; break;
	case STRING:
	return 0; break;
	}
return 0;
}

char GET_CHAR(DATA elem){
switch(elem.type) {
	case LONG:
	return elem.LONG; break;
	case CHAR:
	return elem.CHAR; break;
	case DOUBLE:
	return elem.DOUBLE; break;
	case STRING:
	return 0; break;
	}
return 0;
}

char * GET_STRING(DATA elem){
switch(elem.type) {
	case LONG:
	return 0; break;
	case CHAR:
	return 0; break;
	case DOUBLE:
	return 0; break;
	case STRING:
	return elem.STRING; break;
	}
return 0;	
}				
	
void SUM(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s,GET_LONG(x) + GET_LONG(y));					
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(x) + GET_DOUBLE(y));			
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_DOUBLE(s,GET_LONG(x) + GET_DOUBLE(y));
	else push_DOUBLE(s,GET_DOUBLE(x) + GET_LONG(y));									
}

void LESS(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s,GET_LONG(x) - GET_LONG(y));					
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(x) - GET_DOUBLE(y));			
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_DOUBLE(s,GET_LONG(x) - GET_DOUBLE(y));
	else push_DOUBLE(s,GET_DOUBLE(x) - GET_LONG(y));									
}

void DIV(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s,GET_LONG(y) / GET_LONG(x));					
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(y) / GET_DOUBLE(x);			
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_DOUBLE(s,GET_LONG(y) / GET_DOUBLE(x));
	else push_DOUBLE(s,GET_DOUBLE(y) / GET_LONG(x));
}

void MULT(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s,GET_LONG(x) * GET_LONG(y));					
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(x) * GET_DOUBLE(y));			
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_DOUBLE(s,GET_LONG(x) * GET_DOUBLE(y));
	else push_DOUBLE(s,GET_DOUBLE(x) * GET_LONG(y));									
}

void EXP(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s,pow(GET_LONG(y), GET_LONG(x)));					
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s,pow(GET_DOUBLE(y), GET_DOUBLE(x)));			
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_DOUBLE(s,pow(GET_LONG(y),GET_DOUBLE(x)));
	else push_DOUBLE(s,pow(GET_DOUBLE(y),GET_LONG(x)));									
}

void RES(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s,GET_LONG(y) % GET_LONG(x));					
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(y) % GET_DOUBLE(x));			
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_DOUBLE(s,GET_LONG(y) % GET_DOUBLE(x));
	else push_DOUBLE(s,GET_DOUBLE(y) % GET_LONG(x));									
}

void INC(STACK *s){											
	DATA x = pop(s);																										
	if  (tipo(x) == LONG) push_LONG(s,++GET_LONG(x));					
	else if (tipo(x) == DOUBLE) push_DOUBLE(s,++GET_DOUBLE(x));									
}

void INC(STACK *s){											
	DATA x = pop(s);																										
	if  (tipo(x) == LONG) push_LONG(s,--GET_LONG(x));					
	else if (tipo(x) == DOUBLE) push_DOUBLE(s,--GET_DOUBLE(x));									
}

void AND(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s,GET_LONG(y) & GET_LONG(x));					
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(y) & GET_DOUBLE(x));			
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_DOUBLE(s,GET_LONG(y) & GET_DOUBLE(x));
	else push_DOUBLE(s,GET_DOUBLE(y) & GET_LONG(x));									
}

void OR(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s,GET_LONG(y) | GET_LONG(x));					
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(y) | GET_DOUBLE(x));			
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_DOUBLE(s,GET_LONG(y) | GET_DOUBLE(x));
	else push_DOUBLE(s,GET_DOUBLE(y) | GET_LONG(x));									
}

void XOR(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s,GET_LONG(y) ^ GET_LONG(x));					
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(y) ^ GET_DOUBLE(x));			
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_DOUBLE(s,GET_LONG(y) ^ GET_DOUBLE(x));
	else push_DOUBLE(s,GET_DOUBLE(y) ^ GET_LONG(x));									
}

void NOT(STACK *s){											
	DATA x = pop(s);																										
	if  (tipo(x) == LONG) push_LONG(s,~GET_LONG(x));					
	else if (tipo(x) == DOUBLE) push_DOUBLE(s,~GET_DOUBLE(x));									
}

void ROT(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);
	DATA z = pop(s);													
	if (tipo(x) == tipo(y) == tipo(z) && tipo(x) == LONG) push_LONG(s,GET_LONG(y)); push_LONG(s,GET_LONG(x)); push_LONG(s,GET_LONG(z));				
	else if (tipo(x) == tipo(y) ==tipo(z) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(y)); push_DOUBLE(s,GET_DOUBLE(x)); push_DOUBLE(s,GET_DOUBLE(z));			
	else if ((tipo(x) != tipo(y) && tipo(x) != tipo(z)) && tipo(x) == LONG) push_DOUBLE(s,GET_DOUBLE(y)); push_LONG(s,GET_LONG(x)); push_DOUBLE(s,GET_DOUBLE(z));
	else if ((tipo(x) != tipo(y) && tipo(x) != tipo(z)) && tipo(x) == DOUBLE) push_LONG(s,GET_LONG(y)); push_DOUBLE(s,GET_DOUBLE(x)); push_LONG(s,GET_LONG(z));
	else if (tipo(x) == tipo(y) != tipo(z) && tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(y)); push_DOUBLE(s,GET_DOUBLE(x)); push_LONG(s,GET_LONG(z));
	else if (tipo(x) != tipo(y) == tipo(z) && tipo(x) == DOUBLE) push_LONG(s,GET_LONG(y)); push_DOUBLE(s,GET_DOUBLE(x)); push_DOUBLE(s,GET_DOUBLE(z));
	else if (tipo(x) != tipo(y) == tipo(z) && tipo(x) == LONG) push_DOUBLE(s,GET_DOUBLE(y)); push_LONG(s,GET_LONG(x)); push_DOUBLE(s,GET_DOUBLE(z));
    else if (tipo(x) == tipo(y) != tipo(z) && tipo(x) == LONG) push_LONG(s,GET_LONG(y)); push_LONG(s,GET_LONG(x)); push_DOUBLE(s,GET_DOUBLE(z));
}

void DUP(STACK *s){											
	DATA x = pop(s);																										
	if  (tipo(x) == LONG) push_LONG(s,GET_LONG(x));	push_LONG(s,GET_LONG(x));				
	else if (tipo(x) == DOUBLE) push_DOUBLE(s,GET_DOUBLE(x)); push_DOUBLE(s,GET_DOUBLE(x));								
}

void TRD(STACK *s){											
	DATA x = pop(s);													
	DATA y = pop(s);													
	if (tipo(x) == tipo(y) && tipo(x) == LONG) push_LONG(s, GET_LONG(x)); push_LONG(s, GET_LONG(y));				
	else if (tipo(x) == tipo(y) && tipo(x) == DOUBLE) push_DOUBLE(s, GET_DOUBLE(x)); push_DOUBLE(s, GET_DOUBLE(y));	
	else if (tipo(x) != tipo(y) && tipo(x) == LONG) push_LONG(s, GET_LONG(x)); push_DOUBLE(s, GET_DOUBLE(y));
	else push_DOUBLE(s, GET_DOUBLE(x)); push_LONG(s, GET_LONG(y));							
}

void POP1(STACK *s){											
	DATA x = pop(s);
	x++;								
}

void TOINT(STACK *s){											
	DATA x = pop(s);																										
	push_LONG(s,GET_LONG(x));					
}

#define STACK_OPERATION(_type,_name)			\
	void push_##_name(STACK *s,_type val) { 	\
		DATA elem;				\
		elem.type = _name;			\
		elem._name = val;			\
		push(s, elem);				\
	}						\
	_type pop_##_name(STACK *s) {			\
		DATA elem = pop(s);			\
		return elem._name;			\
	}

STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
