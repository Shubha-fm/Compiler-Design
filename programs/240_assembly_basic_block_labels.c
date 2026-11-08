/* Identify basic block leaders in a minimal linear bytecode.
Instructions: NOP, HALT, JMP target, JZ target. Starts new block after branch. */
#include <stdio.h>
#include <string.h>
int main(void){int n,target[100],leader[100]={0};char op[100][8];
if(scanf("%d",&n)!=1||n<1||n>100)return 1;leader[0]=1;
for(int i=0;i<n;i++){if(scanf("%7s",op[i])!=1)return 1;target[i]=-1;if(!strcmp(op[i],"JMP")||!strcmp(op[i],"JZ")){if(scanf("%d",&target[i])!=1||target[i]<0||target[i]>=n)return 1;}else if(strcmp(op[i],"NOP")&&strcmp(op[i],"HALT"))return 1;}
for(int i=0;i<n;i++)if(target[i]>=0){leader[target[i]]=1;if(i+1<n)leader[i+1]=1;}else if(!strcmp(op[i],"HALT")&&i+1<n)leader[i+1]=1;
printf("leaders:");for(int i=0;i<n;i++)if(leader[i])printf(" %d",i);putchar('\n');return 0;}