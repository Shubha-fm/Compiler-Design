/* Greedy graph coloring in vertex order for a small interference graph.
Input: n, m, m undirected edges. Color numbers start from 0. */
#include <stdio.h>
int main(void){int n,m,g[32][32]={0},color[32];if(scanf("%d%d",&n,&m)!=2||n<1||n>32||m<0||m>1024)return 1;
for(int i=0;i<n;i++)color[i]=-1;
for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n||u==v)return 1;g[u][v]=g[v][u]=1;}
int count=0;for(int i=0;i<n;i++){int used[32]={0};for(int j=0;j<i;j++)if(g[i][j])used[color[j]]=1;int c=0;while(used[c])c++;color[i]=c;if(c+1>count)count=c+1;printf("v%d R%d\n",i,c);}
printf("colors=%d\n",count);return 0;}