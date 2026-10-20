/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>

/* Recognize language a followed by zero or more b. */
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;if(s[0]!='a'){puts("REJECT");return 0;}for(int i=1;s[i];i++)if(s[i]!='b'){puts("REJECT");return 0;}puts("ACCEPT");return 0;}
