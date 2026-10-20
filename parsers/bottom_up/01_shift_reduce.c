/* Deterministic shift/reduce recognizer for E -> E+T|T, T->i, input i(+i)*. */
#include <stdio.h>
#include <string.h>
int main(void){char s[256],stack[512];if(scanf("%255s",s)!=1)return 1;size_t top=0;
for(size_t i=0;s[i];i++){if(s[i]!='i'&&s[i]!='+'){puts("REJECT");return 0;}stack[top++]=s[i];if(stack[top-1]=='i')stack[top-1]='E';if(top>=3&&stack[top-3]=='E'&&stack[top-2]=='+'&&stack[top-1]=='E'){top-=2;stack[top-1]='E';}}
puts(top==1&&stack[0]=='E'?"ACCEPT":"REJECT");return 0;}
