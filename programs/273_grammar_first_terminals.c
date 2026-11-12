/* FIRST sets of a CFG without epsilon rules. Single-letter uppercase
nonterminals, lowercase terminals; one RHS per production. */
#include <stdio.h>
#include <string.h>
int main(void){int n,first[26][26]={{0}},changed=1;char lhs[100],rhs[100][64];
if(scanf("%d",&n)!=1||n<1||n>100)return 1;
for(int i=0;i<n;i++){if(scanf(" %c %63s",&lhs[i],rhs[i])!=2||lhs[i]<'A'||lhs[i]>'Z')return 1;
for(int j=0;rhs[i][j];j++)if(!((rhs[i][j]>='A'&&rhs[i][j]<='Z')||(rhs[i][j]>='a'&&rhs[i][j]<='z')))return 1;}
while(changed){changed=0;for(int i=0;i<n;i++){int a=lhs[i]-'A';char x=rhs[i][0];
if(x>='a'&&x<='z'){if(!first[a][x-'a'])first[a][x-'a']=changed=1;}
else{for(int t=0;t<26;t++)if(first[x-'A'][t]&&!first[a][t])first[a][t]=changed=1;}}}
for(int a=0;a<26;a++){int any=0;for(int t=0;t<26;t++)any|=first[a][t];if(any){printf("%c:",'A'+a);for(int t=0;t<26;t++)if(first[a][t])printf(" %c",'a'+t);putchar('\n');}}
return 0;}