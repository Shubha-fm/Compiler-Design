/* Reverse postorder of directed CFG reachable from 0. */
#include <stdio.h>
static int a[30][30],vis[30],post[30],npost,n;
static void dfs(int u){vis[u]=1;for(int v=0;v<n;v++)if(a[u][v]&&!vis[v])dfs(v);post[npost++]=u;}
int main(void){int m;if(scanf("%d%d",&n,&m)!=2||n<1||n>30||m<0||m>900)return 1;for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;a[u][v]=1;}dfs(0);printf("RPO:");for(int i=npost-1;i>=0;i--)printf(" %d",post[i]);putchar('\n');return 0;}