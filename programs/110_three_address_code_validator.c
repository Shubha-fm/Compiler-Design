/* Validate simple TAC: variable = variable op variable. */
#include <stdio.h>
#include <ctype.h>
int main(void){char d,e,a,o,b,extra;int n=scanf(" %c %c %c %c %c %c",&d,&e,&a,&o,&b,&extra);puts(n==5&&isalpha((unsigned char)d)&&e=='='&&isalpha((unsigned char)a)&&isalpha((unsigned char)b)&&(o=='+'||o=='-'||o=='*'||o=='/')?"VALID":"INVALID");return 0;}