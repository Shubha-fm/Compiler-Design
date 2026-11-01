/* Execute PUSH integers and ADD, printing stack depth after each operation. */
#include <stdio.h>
#include <string.h>
int main(void){char op[16];long st[64];int top=0;while(scanf("%15s",op)==1){if(!strcmp(op,"PUSH")){if(top==64||scanf("%ld",&st[top])!=1)return 1;top++;}else if(!strcmp(op,"ADD")){if(top<2){puts("UNDERFLOW");return 0;}long v=st[top-1];top--;st[top-1]+=v;}else if(!strcmp(op,"HALT"))break;else return 1;printf("depth=%d\n",top);}if(top)printf("result=%ld\n",st[top-1]);return 0;}