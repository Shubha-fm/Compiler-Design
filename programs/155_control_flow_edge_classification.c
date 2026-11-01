/* DFS edge classification of a small directed control-flow graph. */
#include <stdio.h>
static int n,g[20][20],color[20],entry[20],clock_;
static void dfs(int u){color[u]=1;entry[u]=++clock_;for(int v=0;v<n;v++)if(g[u][v]){if(!color[v]){printf("%d->%d TREE\n",u,v);dfs(v);}else if(color[v]==1)printf("%d->%d BACK\n",u,v);else printf("%d->%d %s\n",u,v,entry[u]<entry[v]?"FORWARD":"CROSS");}color[u]=2;}
int main(void){int m;if(scanf("%d%d",&n,&m)!=2||n<1||n>20||m<0||m>400)return 1;for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||b<0||a>=n||b>=n)return 1;g[a][b]=1;}for(int i=0;i<n;i++)if(!color[i])dfs(i);return 0;}