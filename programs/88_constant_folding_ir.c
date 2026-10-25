/* Fold one TAC expression with signed integer literals. */
#include <stdio.h>
#include <string.h>
int main(void){char dst[64],eq[4],op;long a,b,v;if(scanf("%63s %3s %ld %c %ld",dst,eq,&a,&op,&b)!=5||strcmp(eq,"="))return 1;switch(op){case '+':v=a+b;break;case '-':v=a-b;break;case '*':v=a*b;break;case '/':if(!b){puts("DIVISION BY ZERO");return 0;}v=a/b;break;default:puts("UNSUPPORTED");return 0;}printf("%s = %ld\n",dst,v);return 0;}