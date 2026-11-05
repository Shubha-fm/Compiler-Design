/* Convert infix union (|) and explicit concatenation (.) to postfix regex.
   Operands: a-z; parentheses supported; '*' postfix unary quantifier. */
#include <stdio.h>
#include <ctype.h>
static int prec(char c){return c=='|'?1:c=='.'?2:0;}
int main(void){char s[256],stack[256],out[512];int top=0,k=0; if(scanf("%255s",s)!=1)return 1;for(int i=0;s[i];i++){char c=s[i];if(islower((unsigned char)c)||c=='*')out[k++]=c;else if(c=='(')stack[top++]=c;else if(c==')'){while(top&&stack[top-1]!='(')out[k++]=stack[--top];if(!top){puts("INVALID");return 0;}top--;}else if(c=='|'||c=='.'){while(top&&stack[top-1]!='('&&prec(stack[top-1])>=prec(c))out[k++]=stack[--top];stack[top++]=c;}else{puts("INVALID");return 0;}}while(top){if(stack[top-1]=='('){puts("INVALID");return 0;}out[k++]=stack[--top];}out[k]=0;puts(out);return 0;}