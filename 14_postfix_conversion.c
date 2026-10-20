#include <stdio.h>
#include <ctype.h>
int prec(char c){return c=='+'||c=='-'?1:c=='*'||c=='/'?2:0;}
int main(void){
 char s[256],st[256];int top=0;puts("Enter infix expression:");if(!fgets(s,sizeof s,stdin))return 1;
 printf("Postfix: ");
 for(int i=0;s[i];i++){char c=s[i];if(isspace((unsigned char)c))continue;
  if(isalnum((unsigned char)c))putchar(c);
  else if(c=='(')st[top++]=c;
  else if(c==')'){while(top&&st[top-1]!='(')putchar(st[--top]);if(top)top--;}
  else if(prec(c)){while(top&&prec(st[top-1])>=prec(c))putchar(st[--top]);st[top++]=c;}
  else {puts("\nInvalid character");return 1;}
 }
 while(top){if(st[top-1]=='('){puts("\nUnmatched parenthesis");return 1;}putchar(st[--top]);}putchar('\n');return 0;
}