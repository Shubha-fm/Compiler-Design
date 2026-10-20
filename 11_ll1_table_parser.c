#include <stdio.h>
/* Grammar S -> aS | b ; LL(1) predictive parser */
int main(void){
 char s[256],stack[512];int top=0,i=0,ok=1;
 puts("Enter a^n b (e.g. aaab):");if(scanf("%255s",s)!=1)return 1;
 stack[top++]='$';stack[top++]='S';
 while(top&&ok){
  char x=stack[--top],look=s[i]?s[i]:'$';
  if(x=='S'){if(look=='a'){stack[top++]='S';stack[top++]='a';}else if(look=='b')stack[top++]='b';else ok=0;}
  else if(x==look)i++;else ok=0;
 }
 puts(ok&&!s[i]?"Accepted":"Rejected");return 0;
}