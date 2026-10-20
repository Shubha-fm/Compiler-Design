/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <string.h>
/* Generate three-address code for a op b op c with precedence. */
int main(void){char a,b,c,op1,op2;if(scanf(" %c %c %c %c %c",&a,&op1,&b,&op2,&c)!=5)return 1;if(!strchr("+-*/",op1)||!strchr("+-*/",op2)){puts("ERROR");return 0;}int p1=(op1=='*'||op1=='/'),p2=(op2=='*'||op2=='/');if(p2>p1){printf("t1 = %c %c %c\nt2 = %c %c t1\n",b,op2,c,a,op1);}else{printf("t1 = %c %c %c\nt2 = t1 %c %c\n",a,op1,b,op2,c);}return 0;}
