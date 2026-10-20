/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <ctype.h>
/* Recognize hexadecimal integer literals. */
int main(void){char s[100];if(scanf("%99s",s)!=1)return 1;if(s[0]!='0'||(s[1]!='x'&&s[1]!='X')||!s[2]){puts("INVALID");return 0;}for(int i=2;s[i];i++)if(!isxdigit((unsigned char)s[i])){puts("INVALID");return 0;}puts("VALID");return 0;}
