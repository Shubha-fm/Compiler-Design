/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>

/* DFA for nonempty binary multiples of three. */
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;int r=0;for(int i=0;s[i];i++){if(s[i]!='0'&&s[i]!='1'){puts("INVALID");return 0;}r=(2*r+s[i]-'0')%3;}puts(r==0?"ACCEPT":"REJECT");return 0;}
