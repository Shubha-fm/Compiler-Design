/* Simplify conditional jump with constant integer operands.
Input: left relation right target; supports == != < <= > >=. */
#include <stdio.h>
#include <string.h>
int main(void){long a,b;char op[4],label[32];int result;
if(scanf("%ld%3s%ld%31s",&a,op,&b,label)!=4)return 1;
if(!strcmp(op,"=="))result=a==b;else if(!strcmp(op,"!="))result=a!=b;
else if(!strcmp(op,"<"))result=a<b;else if(!strcmp(op,"<="))result=a<=b;
else if(!strcmp(op,">"))result=a>b;else if(!strcmp(op,">="))result=a>=b;
else return 1;
if(result)printf("JMP %s\n",label);else puts("REMOVE BRANCH");
return 0;}