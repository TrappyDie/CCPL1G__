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
 * @def Tamanho usado nos arrays do programa
 */
#define MAX_SIZE	1000
/**
 * \brief Função responsável pela colocação dos elementos do input no stack
 * @param val Input do utilizador
 * @param token String que vai conter todos os operadores e operandos um de cada vez ao longo de toda a execução
 * @param resto String que contém o que sobra do Input do utilizador
 * @param n Char onde vai ser colocada a parte que não tem numeros long da string
 * @param c Char onde vai ser colocada a parte que não tem numeros double da string
 * @param line String com o input dado sempre que é lido um 'l'
 * @param c1 Double que vai ser usado no sscanf para se distinguir o input de um numero e de um char
 * @param l Long onde é guardado um long dado pelo input
 * @param f Float onde é guardado um float dado pelo input
 * @returns A stack resultante do programa
 */
void stacking(char *val, STACK *s){
    char token[MAX_SIZE];
    char resto[MAX_SIZE];
    char line[MAX_SIZE];
    while(sscanf(val, "%s%[^\n]", token, resto) > 0) {
        strcpy(val, resto);
        *resto = 0;
        double c1;
        char *n;
        char *c;
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
        else if (*token == ':'){
            VARCHANGE(s, token[1]);
        }
        else if (*token >= 'A' && *token <= 'Z'){
            VAR(s,*token);
        }
        else switch (*token) {
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
            case 'l' : assert(fgets(line, MAX_SIZE, stdin) != NULL);
                stacking(line,s);
                break;
            case 'f' : TODOB(s);
                break;
            case 'c' : TOCHAR(s);
                break;
            case '$' : CHANGE(s);
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
        }
    }
}
//  --------------------------------------------------------------------------
/**
 * \brief Função principal onde se recebe o input, se cria o stack e se imprime o stack
 * @param val Array onde vai ser guardado o Input
 * @param s Stack
 */
int main(void) {
    STACK *s = create_stack();
    char val[MAX_SIZE];
    assert(fgets(val, MAX_SIZE, stdin) != NULL);
    stacking(val, s);
    print_stack(s);
    return 0;
}
//  --------------------------------------------------------------------------
//---------------------- Code Ending ----------------------
