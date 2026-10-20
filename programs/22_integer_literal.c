/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <ctype.h>
/* Recognize decimal integer literals. */
int main(void){char s[100];if(scanf("%99s",s)!=1)return 1;int i=(s[0]=='+'||s[0]=='-');if(!s[i]){puts("INVALID");return 0;}for(;s[i];i++)if(!isdigit((unsigned char)s[i])){puts("INVALID");return 0;}puts("VALID");return 0;}
