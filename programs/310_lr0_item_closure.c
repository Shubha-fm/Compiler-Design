/* Compute LR(0) closure for non-epsilon single-letter grammar rules.
   Input n, n rules 'A rhs', seed rule-index (0-based).
   Output normalized item positions including closure items. */
#include <stdio.h>
#include <string.h>
static char lhs[40],rhs[40][32];static int items[40][32];
int main(void){int n,seed;if(scanf("%d",&n)!=1||n<1||n>40)return 1;
for(int i=0;i<n;i++){if(scanf(" %c %31s",&lhs[i],rhs[i])!=2||lhs[i]<'A'||lhs[i]>'Z')return 1;
for(int j=0;rhs[i][j];j++)if(!((rhs[i][j]>='A'&&rhs[i][j]<='Z')||(rhs[i][j]>='a'&&rhs[i][j]<='z')))return 1;}
if(scanf("%d",&seed)!=1||seed<0||seed>=n)return 1;items[seed][0]=1;
int changed=1;while(changed){changed=0;for(int i=0;i<n;i++)for(int pos=0;rhs[i][pos];pos++)if(items[i][pos]){char next=rhs[i][pos];if(next>='A'&&next<='Z')for(int j=0;j<n;j++)if(lhs[j]==next&&!items[j][0])items[j][0]=changed=1;}}
for(int i=0;i<n;i++)for(int j=0;j<=(int)strlen(rhs[i]);j++)if(items[i][j])printf("%c -> %.*s.%s\n",lhs[i],j,rhs[i],rhs[i]+j);
return 0;}
