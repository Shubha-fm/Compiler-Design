/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>

/* Print an intermediate-code triple. */
int main(void){char a[40],op[4],b[40];if(scanf("%39s %3s %39s",a,op,b)!=3)return 1;printf("(0) (%s, %s, %s)\n",op,a,b);return 0;}
