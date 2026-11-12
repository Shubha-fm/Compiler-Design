/* Print all ordered reachable pairs of a small directed control flow graph.
Reachability includes zero-length paths from each node to itself. */
#include <stdio.h>
int main(void){int n,m,g[24][24]={0};if(scanf("%d%d",&n,&m)!=2||n<1||n>24||m<0||m>576)return 1;
for(int i=0;i<n;i++)g[i][i]=1;
for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||a>=n||b<0||b>=n)return 1;g[a][b]=1;}
for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(g[i][k]&&g[k][j])g[i][j]=1;
int count=0;for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(g[i][j])count++;
printf("reachable_pairs=%d\n",count);return 0;}