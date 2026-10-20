/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <ctype.h>
/* Recognize decimal floating point literals. */
int main(void){char s[100];if(scanf("%99s",s)!=1)return 1;int i=0,digits=0,dot=0;if(s[i]=='+'||s[i]=='-')i++;for(;s[i];i++){if(isdigit((unsigned char)s[i]))digits++;else if(s[i]=='.'&&!dot)dot=1;else{puts("INVALID");return 0;}}puts(digits&&dot?"VALID":"INVALID");return 0;}
