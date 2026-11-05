/* Educational shift/reduce recognizer for language a^n b, n >= 0.
   Shift input symbols; reduce aS -> S and b -> S, accept single S. */
#include <stdio.h>
#include <string.h>
int main(void){char w[256],st[512];int top=0;if(scanf("%255s",w)!=1)return 1;for(int i=0;w[i];i++){if(w[i]!='a'&&w[i]!='b'){puts("REJECT");return 0;}st[top++]=w[i];printf("shift %c\n",w[i]);if(w[i]=='b'){st[top-1]='S';puts("reduce b -> S");}}while(top>=2&&st[top-2]=='a'&&st[top-1]=='S'){top-=2;st[top++]='S';puts("reduce aS -> S");}puts(top==1&&st[0]=='S'?"ACCEPT":"REJECT");return 0;}