/* Verify consistent stack depths at every reachable instruction of a small
   bytecode control-flow graph. Opcodes PUSH, POP, ADD, JMP, BR, HALT.
   BR consumes one stack value and branches to target or next instruction.
   Input: n, then n opcode lines (JMP and BR have integer target). */
#include <stdio.h>
#include <string.h>
static char op[100][8];static int target[100],height[100],queue[20000];
int main(void){int n;if(scanf("%d",&n)!=1||n<1||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%7s",op[i])!=1)return 1;
if(!strcmp(op[i],"JMP")||!strcmp(op[i],"BR")){if(scanf("%d",&target[i])!=1||target[i]<0||target[i]>=n)return 1;}
else if(strcmp(op[i],"PUSH")&&strcmp(op[i],"POP")&&strcmp(op[i],"ADD")&&strcmp(op[i],"HALT"))return 1;}
for(int i=0;i<n;i++)height[i]=-1;
int head=0,tail=0;height[0]=0;queue[tail++]=0;
while(head<tail){int pc=queue[head++],in=height[pc],pop=0,push=0;
if(!strcmp(op[pc],"PUSH"))push=1;
else if(!strcmp(op[pc],"POP")||!strcmp(op[pc],"BR"))pop=1;
else if(!strcmp(op[pc],"ADD")){pop=2;push=1;}
if(in<pop){printf("UNDERFLOW at %d\n",pc);return 0;}
int out=in-pop+push;
if(!strcmp(op[pc],"HALT"))continue;
int succ[2],count=0;if(!strcmp(op[pc],"JMP"))succ[count++]=target[pc];
else{if(pc+1<n)succ[count++]=pc+1;if(!strcmp(op[pc],"BR"))succ[count++]=target[pc];}
for(int i=0;i<count;i++){int s=succ[i];if(height[s]==-1){height[s]=out;if(tail>=20000)return 1;queue[tail++]=s;}
else if(height[s]!=out){printf("STACK MERGE ERROR at %d\n",s);return 0;}}}
puts("STACK SAFE");return 0;}
