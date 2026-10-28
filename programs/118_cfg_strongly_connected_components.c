/* Kosaraju SCC count for graph of at most 30 vertices. */
#include <stdio.h>
static int n,g[30][30],seen[30],order[30],count;
static void dfs1(int x){seen[x]=1;for(int j=0;j<n;j++)if(g[x][j]&&!seen[j])dfs1(j);order[count++]=x;}
static void dfs2(int x){seen[x]=1;for(int j=0;j<n;j++)if(g[j][x]&&!seen[j])dfs2(j);}
int main(void){int m;if(scanf("%d %d",&n,&m)!=2||n<1||n>30||m<0||m>900)return 1;for(int i=0;i<m;i++){int a,b;if(scanf("%d %d",&a,&b)!=2||a<0||b<0||a>=n||b>=n)return 1;g[a][b]=1;}for(int i=0;i<n;i++)if(!seen[i])dfs1(i);for(int i=0;i<n;i++)seen[i]=0;int scc=0;for(int i=count-1;i>=0;i--)if(!seen[order[i]]){scc++;dfs2(order[i]);}printf("SCC=%d\n",scc);return 0;}