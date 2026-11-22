/* Compute nullable for a postfix regular expression.
   a-z = literal, # = epsilon, . = concatenation, | = union, * = Kleene star. */
#include <stdio.h>
#include <string.h>
int main(void){char s[256];int stack[256],top=0;if(scanf("%255s",s)!=1)return 1;
for(int i=0;s[i];i++){char c=s[i];
if((c>='a'&&c<='z')||c=='#')stack[top++]=c=='#';
else if(c=='*'){if(top<1){puts("INVALID");return 0;}stack[top-1]=1;}
else if(c=='.'||c=='|'){if(top<2){puts("INVALID");return 0;}int b=stack[--top],a=stack[--top];stack[top++]=c=='.'?(a&&b):(a||b);}
else{puts("INVALID");return 0;}}
if(top!=1){puts("INVALID");return 0;}puts(stack[0]?"NULLABLE":"NOT NULLABLE");return 0;}
