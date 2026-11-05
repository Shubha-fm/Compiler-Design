/* Print binary CFG adjacency matrix from block edge pairs; duplicates ignored. */
#include <stdio.h>
int main(void){int n,m,g[30][30]={0};if(scanf("%d%d",&n,&m)!=2||n<1||n>30||m<0||m>900)return 1;for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;g[u][v]=1;}for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d%s",g[i][j],j+1==n?"":" ");putchar('\n');}return 0;}