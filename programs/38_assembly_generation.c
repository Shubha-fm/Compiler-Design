/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <string.h>
/* Translate one arithmetic TAC assignment to pseudo assembly. */
int main(void){char dst[40],eq[4],a[40],op[4],b[40];if(scanf("%39s %3s %39s %3s %39s",dst,eq,a,op,b)!=5)return 1;if(strcmp(eq,"=")||strlen(op)!=1){puts("ERROR");return 0;}const char *ins=op[0]=='+'?"ADD":op[0]=='-'?"SUB":op[0]=='*'?"MUL":op[0]=='/'?"DIV":NULL;if(!ins){puts("ERROR");return 0;}printf("LOAD R0, %s\n%s R0, %s\nSTORE %s, R0\n",a,ins,b,dst);return 0;}
