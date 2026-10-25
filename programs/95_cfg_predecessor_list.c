/* List predecessors of each node in a directed graph. */
#include <stdio.h>
int main(void){int n,m,g[30][30]={0};if(scanf("%d%d",&n,&m)!=2||n<1||n>30||m<0||m>900)return 1;for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||a>=n||b<0||b>=n)return 1;g[a][b]=1;}for(int v=0;v<n;v++){printf("%d:",v);for(int u=0;u<n;u++)if(g[u][v])printf(" %d",u);putchar('\n');}return 0;}