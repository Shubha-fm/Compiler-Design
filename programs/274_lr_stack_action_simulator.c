/* Tiny LR-like action trace simulator: shift token, reduce k items, accept.
Input commands: SHIFT token, REDUCE count symbol, ACCEPT. */
#include <stdio.h>
#include <string.h>
int main(void){char command[16],item[32],stack[100][32];int top=0;
while(scanf("%15s",command)==1){if(!strcmp(command,"SHIFT")){if(top==100||scanf("%31s",item)!=1)return 1;strcpy(stack[top++],item);}
else if(!strcmp(command,"REDUCE")){int n;if(scanf("%d %31s",&n,item)!=2||n<0||n>top)return 1;top-=n;strcpy(stack[top++],item);}
else if(!strcmp(command,"ACCEPT")){printf("stack_top=%s depth=%d\n",top?stack[top-1]:"EMPTY",top);return 0;}
else return 1;}puts("NO ACCEPT");return 0;}