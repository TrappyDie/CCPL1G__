/**
 * @file Contém a função principal do programa
 */
 
 
//  ---------------------------------------------------------
//  Main.c - Main Code
//  Version 1.0 - Beta
//  Revision 1.57
//  Project LAUM2021 CCPL1G03
//  ---------------------------------------------------------
//  ----------------------- Libraries -----------------------
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <assert.h>
#include <math.h>
//  ----------------------- Libraries -----------------------
//  --------------------- Code Begining ---------------------
/**
 * @def MAX_SIZE
 * Usado como tamanho máximo para os arrays
 */
#define MAX_SIZE	10000
 
/**
 * \brief Função que inicializa o array de variáveis
 * @param i Variável usada nos ciclos que indica posições do array usar
 * @param f Variável usada nos ciclos que indica o que colocar no array
 * @param x Variável que tem o que vai ser guardado no array com tipo DATA
 * @param x Variável que tem o que vai ser guardado no array com tipo DATA
 */ 

void initvars(STACK *s, DATA *vars){
long i,f = 10;
for(i = 0; i <= 5; i++){
    push_LONG(s, f);
    DATA x = pop(s);
    vars[i] = x;
    f++;
}
f = 0;
for(i = 23; i <= 25; i++){
    push_LONG(s, f);
    DATA x1 = pop(s);
    vars[i] = x1;
    f++;
}
    push_STRING(s, " ");
    DATA y = pop(s);
    vars[18] = y;
    push_STRING(s, "\n");
    DATA y1 = pop(s);
    vars[13] = y1; 
}
/**
 * \brief Função onde se atribui valores às variáveis
 * @param s Stack onde estão os valores que precisamos
 * @param vars Array onde estão as variáveis
 * @param token variável que temos de mudar
 */


void operacoesvars(char *token, DATA *vars, STACK *s){
    if (*token >= 'A' && *token <= 'Z'){
            long i = *token;
            DATA x = vars[i - 65];
            push(s, x);}
    else if (*token == ':'){
            long l = token[1];
            DATA w = pop(s);
            vars[l - 65] = w; 
            push(s,w);
    }
}          



/**
 * \brief Função onde são chamadas as funções relativas a cada operação lógica
 * @param s Stack onde estão os valores que precisamos
 * @param token operando que vamos executar
 */
void operacoeslogicas(char *token, STACK *s, DATA *vars){
    switch (*token)
    {
       case ')' : INC(s);
           break;
       case '(' : DEC(s);
           break;
       case '&' : AND(s);
           break;
       case '|' : OR(s);
           break;
       case '^' : XOR(s);
           break;
       case '~' : NOT(s);
           break;
       case '=' : EQL(s);
           break;
       case '<' : LESS(s);
           break;
       case '>' : HIGH(s);
           break;
       case '!' : NAO(s);
           break;
       case 'e' : switch (token[1]){
           case '&' : AND2(s);
               break;
           case '|' : OR2(s);
               break;
           case '<' : PUTMEN(s);
               break;
           case '>' : PUTMAI(s);
               break;
       }
           break;
       case '?' : IF(s);
           break; 
       default : operacoesvars(token, vars, s); 
           break;  
    }
}


//  ---------------------------------------------------------
/**
 * \brief Função onde são chamadas as funções relativas a cada operação
 */
void operacoes(char *token, STACK *s, DATA *vars, char *resto, char *val){              
switch (*token){
       case '+' : SUM(s);
           break;
       case '-' : MINUS(s);
           break;
       case '/' : DIV(s);
           break;
       case '*' : MULT(s);
           break;
       case '#' : EXP(s);
           break;
       case '%' : RES(s); 
           break;   
       case '@' : ROT(s);
           break;
       case '_' : DUP(s);
           break;
       case ';' : POP1(s);
           break;
       case '\\' : TRD(s);
           break;
       case 'i' : TOINT(s);
           break;
       case 'l' : READ(s);
           break;
       case 'f' : TODOB(s);
           break;
       case 'c' : TOCHAR(s);
           break;
       case '$' : CHANGE(s);
           break;
       case ',' : SIZE(s);
           break;
       case '\"' : {STRINGET(s, token + 1, resto,val);strcpy(val, resto);}
           break;
       case 't' : READ2(s);
           break;
       case 'S' : if (token[1] == '/') WHITE(s);
                  else operacoesvars(token,vars, s);
           break;
       case 'N' : if (token[1] == '/') NEW(s);
                  else operacoesvars(token,vars,s);
           break;                 
       default : operacoeslogicas(token, s, vars);
           break;           
}
}

//  ---------------------------------------------------------
/**
 * \brief Função responsável pela colocação dos elementos do input no stack
 * @param val Pointer para o input do utilizador
 * @param token String que vai conter todos os operadores e operandos um de cada vez ao longo de toda a execução
 * @param resto String que contém o que sobra do Input do utilizador
 * @param n Char onde vai ser colocada a parte que não tem numeros long da string
 * @param c Char onde vai ser colocada a parte que não tem numeros double da string
 * @param line String com o input dado sempre que é lido um 'l'
 * @param c1 Double que vai ser usado no sscanf para se distinguir o input de um numero e de um char
 * @param l Long onde é guardado um long dado pelo input
 * @param f Float onde é guardado um float dado pelo input
 * @param vars Array de variáveis
 * @returns A stack resultante do programa
 */
 
void stacking(char *val, STACK *s, DATA *vars){
    char token[MAX_SIZE];
    char resto[MAX_SIZE];
    double c1;
    char *n;
    char *c;
    while(sscanf(val, "%s%[^\n]", token, resto) > 0) {
        strcpy(val, resto);
         if (sscanf(token, "%lf", &c1) == 1) {
            long l = strtol(token, &n, 10);                                                   
            float f = strtod(token, &c);
            if (strlen(n) == 0){
                push_LONG(s, l);
            }
            else if (strlen(c) == 0){
                push_DOUBLE(s,f);       
            }
        }      
        else if (*token == '[') {
                       char *line1 = get_delimited(val, token, resto);
                       STACK *s1 = create_stack();
                       stacking(line1, s1, vars);
                       push_ARRAY(s,s1);
        }
        else operacoes(token,s,vars,resto,val);
         strcpy(val, resto);
         *resto = 0;
         }
}
          	        

//  --------------------------------------------------------------------------
/**
 * \brief Função principal onde se recebe o input, se cria o stack e se imprime o stack
 * @param val Array onde vai ser guardado o Input
 * @param s Stack
 */
int main(void) {
    DATA vars[26];
    STACK *s = create_stack();
    initvars(s, vars);
    char val[MAX_SIZE];
    assert(fgets(val, MAX_SIZE, stdin) != NULL);
    stacking(val, s, vars);
    print_stack(s);
    return 0;
}
//  --------------------------------------------------------------------------
//---------------------- Code Ending ----------------------
