/* Simplify one TAC expression with safe algebraic identities (+0,*1,*0).
   Integer-like pure operands assumed, no side effects. */
#include <stdio.h>
#include <string.h>
int main(void){char dst[32],a[32],b[32],op[8],eq[8];if(scanf("%31s%7s%31s%7s%31s",dst,eq,a,op,b)!=5)return 1;if(strcmp(eq,"="))return 1;const char *x=NULL;if(!strcmp(op,"+")){if(!strcmp(b,"0"))x=a;else if(!strcmp(a,"0"))x=b;}else if(!strcmp(op,"*")){if(!strcmp(a,"0")||!strcmp(b,"0"))x="0";else if(!strcmp(a,"1"))x=b;else if(!strcmp(b,"1"))x=a;}if(x)printf("%s = %s\n",dst,x);else printf("%s = %s %s %s\n",dst,a,op,b);return 0;}