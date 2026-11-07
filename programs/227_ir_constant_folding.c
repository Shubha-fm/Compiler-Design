/* Fold integer constant binary expression for +,-,*,/ (nonzero divisor).
Small classroom example, no overflow detection. */
#include <stdio.h>
#include <string.h>
int main(void){char dst[32],eq[4],op[4];long a,b,v;
if(scanf("%31s %3s %ld %3s %ld",dst,eq,&a,op,&b)!=5||strcmp(eq,"="))return 1;
if(!strcmp(op,"+"))v=a+b;else if(!strcmp(op,"-"))v=a-b;else if(!strcmp(op,"*"))v=a*b;else if(!strcmp(op,"/")){if(!b){puts("DIVISION BY ZERO");return 0;}v=a/b;}else{puts("UNSUPPORTED");return 0;}
printf("%s = %ld\n",dst,v);return 0;}