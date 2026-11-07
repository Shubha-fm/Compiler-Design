/* Articulation vertices of the undirected graph underlying a CFG. */
#include <stdio.h>
static int n,g[40][40],disc[40],low[40],parent[40],cut[40],clock_;
static void dfs(int u){disc[u]=low[u]=++clock_;int child=0;
for(int v=0;v<n;v++)if(g[u][v]){if(!disc[v]){parent[v]=u;child++;dfs(v);if(low[v]<low[u])low[u]=low[v];if(parent[u]>=0&&low[v]>=disc[u])cut[u]=1;}else if(v!=parent[u]&&disc[v]<low[u])low[u]=disc[v];}
if(parent[u]<0&&child>1)cut[u]=1;}
int main(void){int m;if(scanf("%d%d",&n,&m)!=2||n<1||n>40||m<0||m>1600)return 1;
for(int i=0;i<n;i++)parent[i]=-1;
for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||a>=n||b<0||b>=n)return 1;if(a!=b)g[a][b]=g[b][a]=1;}
for(int i=0;i<n;i++)if(!disc[i])dfs(i);
printf("articulation:");for(int i=0;i<n;i++)if(cut[i])printf(" %d",i);putchar('\n');return 0;}