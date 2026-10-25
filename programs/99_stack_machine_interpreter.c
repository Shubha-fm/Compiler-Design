/* Small stack-machine evaluator: PUSH n, ADD, SUB, MUL, PRINT, HALT. */
#include <stdio.h>
#include <string.h>
int main(void){long st[128],v;int top=0;char op[16];while(scanf("%15s",op)==1){if(!strcmp(op,"PUSH")){if(scanf("%ld",&v)!=1||top==128)return 1;st[top++]=v;}else if(!strcmp(op,"HALT"))break;else if(!strcmp(op,"PRINT")){if(top<1)return 1;printf("%ld\n",st[top-1]);}else{if(top<2)return 1;long b=st[--top],a=st[--top];if(!strcmp(op,"ADD"))st[top++]=a+b;else if(!strcmp(op,"SUB"))st[top++]=a-b;else if(!strcmp(op,"MUL"))st[top++]=a*b;else return 1;}}return 0;}