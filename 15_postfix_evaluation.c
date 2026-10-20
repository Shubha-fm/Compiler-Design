#include <stdio.h>
#include <ctype.h>
int main(void){
 char s[256];long st[256];int top=0;
 puts("Postfix single-digit expression (e.g. 23+4*):");if(scanf("%255s",s)!=1)return 1;
 for(int i=0;s[i];i++){char c=s[i];
  if(isdigit((unsigned char)c))st[top++]=c-'0';
  else if(c=='+'||c=='-'||c=='*'||c=='/'){
   if(top<2){puts("Invalid expression");return 1;}
   long b=st[--top],a=st[--top];
   if(c=='/'&&b==0){puts("Division by zero");return 1;}
   st[top++]=c=='+'?a+b:c=='-'?a-b:c=='*'?a*b:a/b;
  }else {puts("Invalid token");return 1;}
 }
 if(top!=1){puts("Invalid expression");return 1;}printf("Result: %ld\n",st[0]);return 0;
}