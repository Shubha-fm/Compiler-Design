/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <string.h>
/* Print quadruple fields for an arithmetic operation. */
int main(void){char a[40],op[4],b[40];if(scanf("%39s %3s %39s",a,op,b)!=3)return 1;if(strlen(op)!=1||!strchr("+-*/",op[0])){puts("ERROR");return 0;}printf("op=%s arg1=%s arg2=%s result=t1\n",op,a,b);return 0;}
