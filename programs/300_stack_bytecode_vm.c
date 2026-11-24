/* Tiny stack VM: PUSH integer, ADD, SUB, MUL, DUP, PRINT, HALT.
   Enter instruction count and instructions; reject stack underflow.
   Programs execute in linear order without jumps. */
#include <stdio.h>
#include <string.h>
int main(void){int n,stack[128],top=0;if(scanf("%d",&n)!=1||n<0||n>256)return 1;
for(int pc=0;pc<n;pc++){char op[16];if(scanf("%15s",op)!=1)return 1;
if(!strcmp(op,"PUSH")){int x;if(scanf("%d",&x)!=1||top>=128)return 1;stack[top++]=x;}
else if(!strcmp(op,"DUP")){if(top<1||top>=128){puts("STACK ERROR");return 0;}stack[top]=stack[top-1];top++;}
else if(!strcmp(op,"ADD")||!strcmp(op,"SUB")||!strcmp(op,"MUL")){if(top<2){puts("STACK ERROR");return 0;}int b=stack[--top],a=stack[--top];stack[top++]=!strcmp(op,"ADD")?a+b:!strcmp(op,"SUB")?a-b:a*b;}
else if(!strcmp(op,"PRINT")){if(top<1){puts("STACK ERROR");return 0;}printf("OUTPUT %d\n",stack[top-1]);}
else if(!strcmp(op,"HALT")){printf("HALT depth=%d\n",top);return 0;}else return 1;}
printf("END depth=%d\n",top);return 0;}
