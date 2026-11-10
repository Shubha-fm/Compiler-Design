/* Productive nonterminals by fixed point. Rule: A rhs, '-' = epsilon.
Only uppercase nonterminals and lowercase terminals are supported. */
#include <stdio.h>
int main(void){int n,productive[26]={0},changed=1;char lhs[128],rhs[128][64];
if(scanf("%d",&n)!=1||n<0||n>128)return 1;
for(int i=0;i<n;i++){if(scanf(" %c %63s",&lhs[i],rhs[i])!=2||lhs[i]<'A'||lhs[i]>'Z')return 1;
for(int j=0;rhs[i][j];j++)if(!((rhs[i][j]>='A'&&rhs[i][j]<='Z')||(rhs[i][j]>='a'&&rhs[i][j]<='z')||(rhs[i][j]=='-'&&j==0&&!rhs[i][1])))return 1;}
while(changed){changed=0;for(int i=0;i<n;i++){int ok=1;for(int j=0;rhs[i][j];j++){char c=rhs[i][j];if(c>='A'&&c<='Z'&&!productive[c-'A'])ok=0;}
if(ok&&!productive[lhs[i]-'A']){productive[lhs[i]-'A']=1;changed=1;}}}
printf("productive:");for(int i=0;i<26;i++)if(productive[i])printf(" %c",'A'+i);putchar('\n');return 0;}