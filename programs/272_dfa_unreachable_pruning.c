/* Print reachable binary DFA states; unreachable states may be removed. */
#include <stdio.h>
int main(void){int n,s,d[40][2],vis[40]={0},q[40],h=0,t=0;
if(scanf("%d%d",&n,&s)!=2||n<1||n>40||s<0||s>=n)return 1;
for(int i=0;i<n;i++)for(int c=0;c<2;c++)if(scanf("%d",&d[i][c])!=1||d[i][c]<0||d[i][c]>=n)return 1;
vis[s]=1;q[t++]=s;while(h<t){int u=q[h++];for(int c=0;c<2;c++){int v=d[u][c];if(!vis[v])vis[v]=1,q[t++]=v;}}
printf("keep:");for(int i=0;i<n;i++)if(vis[i])printf(" %d",i);putchar('\n');
printf("removed=%d\n",n-t);return 0;}