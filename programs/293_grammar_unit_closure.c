/* Compute unit-production closure A =>* B for a CFG.
   Input: n unit productions (uppercase A B), then queried A. */
#include <stdio.h>
int main(void){int n,g[26][26]={0};char a,b,query;if(scanf("%d",&n)!=1||n<0||n>676)return 1;
for(int i=0;i<26;i++)g[i][i]=1;
for(int i=0;i<n;i++){if(scanf(" %c %c",&a,&b)!=2||a<'A'||a>'Z'||b<'A'||b>'Z')return 1;g[a-'A'][b-'A']=1;}
if(scanf(" %c",&query)!=1||query<'A'||query>'Z')return 1;
for(int k=0;k<26;k++)for(int i=0;i<26;i++)for(int j=0;j<26;j++)if(g[i][k]&&g[k][j])g[i][j]=1;
printf("closure(%c):",query);for(int j=0;j<26;j++)if(g[query-'A'][j])printf(" %c",'A'+j);putchar('\n');return 0;}
