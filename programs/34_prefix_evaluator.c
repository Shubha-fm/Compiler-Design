/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Evaluate space-separated binary prefix expression. */
int main(void){char s[256],*tok[128],*p;int n=0;long stack[128];int top=0;if(!fgets(s,sizeof s,stdin))return 1;for(p=strtok(s," \t\r\n");p&&n<128;p=strtok(NULL," \t\r\n"))tok[n++]=p;for(int i=n-1;i>=0;i--){if(strlen(tok[i])==1&&strchr("+-*/",tok[i][0])){if(top<2){puts("ERROR");return 0;}long a=stack[--top],b=stack[--top],v=0;switch(tok[i][0]){case '+':v=a+b;break;case '-':v=a-b;break;case '*':v=a*b;break;case '/':if(!b){puts("ERROR");return 0;}v=a/b;}stack[top++]=v;}else{char *end;long v=strtol(tok[i],&end,10);if(end==tok[i]||*end){puts("ERROR");return 0;}stack[top++]=v;}}if(top!=1){puts("ERROR");return 0;}printf("%ld\n",stack[0]);return 0;}
