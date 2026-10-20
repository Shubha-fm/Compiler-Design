/* Find unreachable vertices in control flow graph. Educational, limited-scope lab example. */
#include <stdio.h>

int main(void){int n,m,a,b,adj[30][30]={0},vis[30]={0},queue[30],h=0,t=0;if(scanf("%d %d",&n,&m)!=2||n<1||n>30||m<0||m>900)return 1;for(int i=0;i<m;i++){if(scanf("%d %d",&a,&b)!=2||a<0||a>=n||b<0||b>=n)return 1;adj[a][b]=1;}queue[t++]=0;vis[0]=1;while(h<t){int x=queue[h++];for(int y=0;y<n;y++)if(adj[x][y]&&!vis[y]){vis[y]=1;queue[t++]=y;}}printf("Unreachable:");for(int i=0;i<n;i++)if(!vis[i])printf(" %d",i);putchar('\n');return 0;}
