/* Convert explicit-concatenation infix regex to postfix.
   Operators: * highest, . concatenation, | alternation. Parentheses group. */
#include <stdio.h>
#include <string.h>
static int prec(char c){return c=='|'?1:c=='.'?2:0;}
int main(void){char expr[256],ops[256],out[256];int top=0,len=0,need=1;
if(scanf("%255s",expr)!=1)return 1;
for(int i=0;expr[i];i++){char c=expr[i];
if(c>='a'&&c<='z'){if(!need){puts("INVALID");return 0;}out[len++]=c;need=0;}
else if(c=='('){if(!need){puts("INVALID");return 0;}ops[top++]=c;need=1;}
else if(c==')'){if(need){puts("INVALID");return 0;}int found=0;
while(top){char op=ops[--top];if(op=='('){found=1;break;}out[len++]=op;}
if(!found){puts("INVALID");return 0;}need=0;}
else if(c=='*'){if(need){puts("INVALID");return 0;}out[len++]=c;}
else if(c=='.'||c=='|'){if(need){puts("INVALID");return 0;}
while(top&&ops[top-1]!='('&&prec(ops[top-1])>=prec(c))out[len++]=ops[--top];
ops[top++]=c;need=1;}else{puts("INVALID");return 0;}}
if(need){puts("INVALID");return 0;}
while(top){char op=ops[--top];if(op=='('){puts("INVALID");return 0;}out[len++]=op;}
out[len]=0;puts(out);return 0;}
