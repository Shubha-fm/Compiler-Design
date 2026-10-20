/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <string.h>
/* Recognize palindrome strings over a and b. */
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;int n=(int)strlen(s);for(int i=0;i<n;i++)if((s[i]!='a'&&s[i]!='b')||s[i]!=s[n-1-i]){puts("REJECT");return 0;}puts("ACCEPT");return 0;}
