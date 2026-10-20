/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>

/* Recognize context-free language a^n b^n for n>=1. */
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;int a=0,b=0,i=0;while(s[i]=='a'){a++;i++;}while(s[i]=='b'){b++;i++;}puts(a>0&&a==b&&!s[i]?"ACCEPT":"REJECT");return 0;}
