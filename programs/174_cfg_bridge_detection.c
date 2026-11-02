/* Bridges in undirected graph underlying a CFG: removal disconnects vertices.
   This does NOT compute directed strong bridges. */
#include <stdio.h>
static int n,g[32][32],vis[32],tin[32],low[32],timer;
static void dfs(int u,int parent){vis[u]=1;tin[u]=low[u]=++timer;for(int v=0;v<n;v++)if(g[u][v]){if(v==parent)continue;if(vis[v]){if(tin[v]<low[u])low[u]=tin[v];}else{dfs(v,u);if(low[v]<low[u])low[u]=low[v];if(low[v]>tin[u])printf("bridge %d %d\n",u,v);}}}
int main(void){int m;if(scanf("%d%d",&n,&m)!=2||n<1||n>32||m<0||m>1024)return 1;for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;g[u][v]=g[v][u]=1;}for(int i=0;i<n;i++)if(!vis[i])dfs(i,-1);return 0;}