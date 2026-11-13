/* Find all CFG blocks that can reach a given exit using reverse BFS. */
#include <stdio.h>
int main(void){int n,m,target,g[40][40]={0},vis[40]={0},q[40],h=0,t=0;
if(scanf("%d%d%d",&n,&m,&target)!=3||n<1||n>40||m<0||m>1600||target<0||target>=n)return 1;
for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||a>=n||b<0||b>=n)return 1;g[a][b]=1;}
vis[target]=1;q[t++]=target;while(h<t){int v=q[h++];for(int u=0;u<n;u++)if(g[u][v]&&!vis[u])vis[u]=1,q[t++]=u;}
printf("can_reach_exit:");for(int i=0;i<n;i++)if(vis[i])printf(" %d",i);putchar('\n');return 0;}