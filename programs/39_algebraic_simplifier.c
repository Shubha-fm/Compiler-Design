/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <string.h>
/* Simplify identities x+0, x*1, x*0. */
int main(void){char a[40],op[4],b[40];if(scanf("%39s %3s %39s",a,op,b)!=3)return 1;if(!strcmp(op,"+")&&!strcmp(b,"0"))puts(a);else if(!strcmp(op,"+")&&!strcmp(a,"0"))puts(b);else if(!strcmp(op,"*")&&(!strcmp(a,"0")||!strcmp(b,"0")))puts("0");else if(!strcmp(op,"*")&&!strcmp(b,"1"))puts(a);else if(!strcmp(op,"*")&&!strcmp(a,"1"))puts(b);else printf("%s %s %s\n",a,op,b);return 0;}
