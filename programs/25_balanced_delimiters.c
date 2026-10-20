/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>

/* Check nested parentheses, braces and brackets. */
int main(void){char s[512],st[512];int top=0,ok=1;if(!fgets(s,sizeof s,stdin))return 1;for(int i=0;s[i];i++){char c=s[i];if(c=='('||c=='['||c=='{')st[top++]=c;else if(c==')'||c==']'||c=='}'){if(!top){ok=0;break;}char p=st[--top];if(!((p=='('&&c==')')||(p=='['&&c==']')||(p=='{'&&c=='}'))){ok=0;break;}}}puts(ok&&!top?"BALANCED":"UNBALANCED");return 0;}
