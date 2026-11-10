/* Compute interference graph degrees, ignoring duplicate undirected edges. */
#include <stdio.h>
int main(void){int n,m,g[50][50]={0};
if(scanf("%d%d",&n,&m)!=2||n<1||n>50||m<0||m>2500)return 1;
for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||v<0||u>=n||v>=n||u==v)return 1;g[u][v]=g[v][u]=1;}
for(int i=0;i<n;i++){int degree=0;for(int j=0;j<n;j++)degree+=g[i][j];printf("v%d degree=%d\n",i,degree);}return 0;}