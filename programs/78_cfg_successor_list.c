/* Build successor list of small control-flow graph. */
#include <stdio.h>
int main(void){int n,m,adj[20][20]={0};if(scanf("%d%d",&n,&m)!=2||n<1||n>20||m<0||m>400)return 1;for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||b<0||a>=n||b>=n)return 1;adj[a][b]=1;}for(int i=0;i<n;i++){printf("%d:",i);for(int j=0;j<n;j++)if(adj[i][j])printf(" %d",j);putchar('\n');}return 0;}