/* Compute a FOLLOW contribution for A -> B C given FIRST(C), nullable(C).
   Input: FIRST(C) lowercase token, nullable 0/1, FOLLOW(A) lowercase token.
   '-' denotes an empty set. */
#include <stdio.h>
#include <string.h>
int main(void){char first[128],follow[128];int nullable,flags[26]={0};if(scanf("%127s%d%127s",first,&nullable,follow)!=3||(nullable!=0&&nullable!=1))return 1;for(int i=0;first[i];i++)if(first[i]!='-'){if(first[i]<'a'||first[i]>'z')return 1;flags[first[i]-'a']=1;}if(nullable)for(int i=0;follow[i];i++)if(follow[i]!='-'){if(follow[i]<'a'||follow[i]>'z')return 1;flags[follow[i]-'a']=1;}printf("FOLLOW_B:");for(int i=0;i<26;i++)if(flags[i])printf(" %c",'a'+i);putchar('\n');return 0;}