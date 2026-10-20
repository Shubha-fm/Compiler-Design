/* Table-driven LL(1) parser for S -> aS | b. */
#include <stdio.h>
#include <string.h>
int main(void){char s[256],st[512];if(scanf("%255s",s)!=1)return 1;size_t i=0,top=0;st[top++]='$';st[top++]='S';
while(top){char x=st[--top],look=s[i]?s[i]:'$';if(x=='S'){if(look=='a'){st[top++]='S';st[top++]='a';}else if(look=='b')st[top++]='b';else{puts("REJECT");return 0;}}else if(x==look){if(x!='$')i++;}else{puts("REJECT");return 0;}}
puts(s[i]?"REJECT":"ACCEPT");return 0;}
