/* Reverse DFS postorder for a CFG rooted at node 0. */
#include <stdio.h>
static int n,g[40][40],visited[40],order[40],count;
static void dfs(int u){visited[u]=1;for(int v=0;v<n;v++)if(g[u][v]&&!visited[v])dfs(v);order[count++]=u;}
int main(void){int m;if(scanf("%d%d",&n,&m)!=2||n<1||n>40||m<0||m>1600)return 1;for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||b<0||a>=n||b>=n)return 1;g[a][b]=1;}dfs(0);printf("RPO:");for(int i=count-1;i>=0;i--)printf(" %d",order[i]);putchar('\n');return 0;}