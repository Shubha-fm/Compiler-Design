/* DFS classification of back edges (edge to gray DFS ancestor). */
#include <stdio.h>
static int g[30][30],color[30],n;
static void dfs(int u){color[u]=1;for(int v=0;v<n;v++)if(g[u][v]){if(color[v]==1)printf("BACK %d %d\n",u,v);else if(!color[v])dfs(v);}color[u]=2;}
int main(void){int m;if(scanf("%d%d",&n,&m)!=2||n<1||n>30||m<0||m>900)return 1;for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||b<0||a>=n||b>=n)return 1;g[a][b]=1;}for(int i=0;i<n;i++)if(!color[i])dfs(i);return 0;}