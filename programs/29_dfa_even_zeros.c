/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>

/* DFA accepting even number of zeros. */
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;int parity=0;for(int i=0;s[i];i++){if(s[i]!='0'&&s[i]!='1'){puts("INVALID");return 0;}if(s[i]=='0')parity^=1;}puts(parity?"REJECT":"ACCEPT");return 0;}
