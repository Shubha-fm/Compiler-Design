/* Kahn topological order for directed acyclic control-flow graphs. */
#include <stdio.h>
int main(void){int n,m,g[40][40]={{0}},indeg[40]={0},q[40],head=0,tail=0,count=0,order[40];
if(scanf("%d%d",&n,&m)!=2||n<1||n>40||m<0||m>1600)return 1;
for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;if(!g[u][v]){g[u][v]=1;indeg[v]++;}}
for(int i=0;i<n;i++)if(!indeg[i])q[tail++]=i;
while(head<tail){int u=q[head++];order[count++]=u;
for(int v=0;v<n;v++)if(g[u][v]&&!--indeg[v])q[tail++]=v;}
if(count<n){puts("CYCLE");return 0;}printf("topological:");for(int i=0;i<n;i++)printf(" %d",order[i]);putchar('\n');return 0;}