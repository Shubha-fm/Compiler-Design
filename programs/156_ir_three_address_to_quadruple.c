/* Convert one TAC assignment into a quadruple. */
#include <stdio.h>
#include <string.h>
int main(void){char dest[40],eq[4],a[40],op[4],b[40];if(scanf("%39s %3s %39s %3s %39s",dest,eq,a,op,b)!=5)return 1;if(strcmp(eq,"=")||strlen(op)!=1||!strchr("+-*/",op[0])){puts("INVALID");return 0;}printf("(%s,%s,%s,%s)\n",op,a,b,dest);return 0;}