/* Remove adjacent PUSH x / POP x pairs in a restricted IR.
Input: n, then n opcode operand pairs. */
#include <stdio.h>
#include <string.h>
int main(void){int n;char op[100][16],arg[100][32];if(scanf("%d",&n)!=1||n<0||n>100)return 1;for(int i=0;i<n;i++)if(scanf("%15s%31s",op[i],arg[i])!=2)return 1;for(int i=0;i<n;i++){if(i+1<n&&!strcmp(op[i],"PUSH")&&!strcmp(op[i+1],"POP")&&!strcmp(arg[i],arg[i+1])){i++;continue;}printf("%s %s\n",op[i],arg[i]);}return 0;}