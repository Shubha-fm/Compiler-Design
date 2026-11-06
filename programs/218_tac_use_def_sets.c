/* Print USE and DEF for simplified assignment: dst = lhs op rhs. */
#include <stdio.h>
#include <string.h>
int main(void){char dst[32],eq[4],a[32],op[4],b[32];if(scanf("%31s %3s %31s %3s %31s",dst,eq,a,op,b)!=5||strcmp(eq,"=")||strlen(op)!=1||!strchr("+-*/",op[0]))return 1;printf("USE: %s",a);if(strcmp(a,b))printf(" %s",b);printf("\nDEF: %s\n",dst);return 0;}