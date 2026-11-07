/* Validate jump target indices in a tiny bytecode instruction list.
Input: n; each instruction HALT, NOP, or JMP target. */
#include <stdio.h>
#include <string.h>
int main(void){int n,targets[100];char op[100][8];if(scanf("%d",&n)!=1||n<1||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%7s",op[i])!=1)return 1;targets[i]=-1;if(!strcmp(op[i],"JMP")){if(scanf("%d",&targets[i])!=1)return 1;}else if(strcmp(op[i],"NOP")&&strcmp(op[i],"HALT"))return 1;}
for(int i=0;i<n;i++)if(!strcmp(op[i],"JMP")&&(targets[i]<0||targets[i]>=n)){printf("INVALID TARGET at %d\n",i);return 0;}
puts("VALID TARGETS");return 0;}