/* Evaluate a postfix integer expression, with whitespace-separated tokens. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){char token[64],*end;long st[128];int n=0;while(scanf("%63s",token)==1){long x=strtol(token,&end,10);if(end!=token&&!*end){if(n==128)return 1;st[n++]=x;}else if(strlen(token)==1&&strchr("+-*",token[0])){if(n<2){puts("INVALID");return 0;}long b=st[--n],a=st[--n];st[n++]=token[0]=='+'?a+b:token[0]=='-'?a-b:a*b;}else{puts("INVALID");return 0;}}if(n!=1)puts("INVALID");else printf("value=%ld\n",st[0]);return 0;}