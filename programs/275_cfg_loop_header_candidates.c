/* DFS back-edge targets indicate possible loop headers.
Not a substitute for dominance-based natural-loop detection. */
#include <stdio.h>
static int n,g[40][40],color[40],header[40];
static void dfs(int u){color[u]=1;for(int v=0;v<n;v++)if(g[u][v]){if(color[v]==1)header[v]=1;else if(!color[v])dfs(v);}color[u]=2;}
int main(void){int m;if(scanf("%d%d",&n,&m)!=2||n<1||n>40||m<0||m>1600)return 1;
for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||a>=n||b<0||b>=n)return 1;g[a][b]=1;}
for(int i=0;i<n;i++)if(!color[i])dfs(i);
printf("headers:");for(int i=0;i<n;i++)if(header[i])printf(" %d",i);putchar('\n');return 0;}