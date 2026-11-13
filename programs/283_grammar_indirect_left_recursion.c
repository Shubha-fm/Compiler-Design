/* Identify nonterminals participating in left recursion using first-symbol
dependencies, assuming no nullable prefixes. Input: A RHS productions. */
#include <stdio.h>
int main(void){int n,g[26][26]={0};char a,rhs[64];
if(scanf("%d",&n)!=1||n<0||n>200)return 1;
for(int i=0;i<n;i++){if(scanf(" %c %63s",&a,rhs)!=2||a<'A'||a>'Z')return 1;
if(rhs[0]>='A'&&rhs[0]<='Z')g[a-'A'][rhs[0]-'A']=1;}
for(int k=0;k<26;k++)for(int i=0;i<26;i++)for(int j=0;j<26;j++)if(g[i][k]&&g[k][j])g[i][j]=1;
printf("left_recursive:");for(int i=0;i<26;i++)if(g[i][i])printf(" %c",'A'+i);putchar('\n');return 0;}