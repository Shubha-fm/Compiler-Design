/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>

/* Simulate NFA accepting words ending in ab. */
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;int states=1;for(int i=0;s[i];i++){if(s[i]!='a'&&s[i]!='b'){puts("INVALID");return 0;}int next=1;if(s[i]=='a')next|=2;if((states&2)&&s[i]=='b')next|=4;states=next;}puts(states&4?"ACCEPT":"REJECT");return 0;}
