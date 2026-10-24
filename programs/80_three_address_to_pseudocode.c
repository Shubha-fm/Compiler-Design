/* Translate simple addition TAC: t = a + b into stack machine pseudocode. */
#include <stdio.h>
#include <string.h>
int main(void){char dst[40],eq[4],a[40],op[4],b[40];if(scanf("%39s %3s %39s %3s %39s",dst,eq,a,op,b)!=5)return 1;if(strcmp(eq,"=")||strcmp(op,"+")){puts("UNSUPPORTED");return 0;}printf("PUSH %s\nPUSH %s\nADD\nPOP %s\n",a,b,dst);return 0;}