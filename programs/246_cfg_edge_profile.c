/* Count traversals of each directed CFG edge from one block execution trace.
Input n, length, and exactly length vertex identifiers. */
#include <stdio.h>
int main(void){int n,len,edge[30][30]={0},last=-1;
if(scanf("%d%d",&n,&len)!=2||n<1||n>30||len<1||len>10000)return 1;
for(int i=0;i<len;i++){int v;if(scanf("%d",&v)!=1||v<0||v>=n)return 1;if(last>=0)edge[last][v]++;last=v;}
for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(edge[i][j])printf("%d->%d: %d\n",i,j,edge[i][j]);return 0;}