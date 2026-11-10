/* Count reachable states of a product of two complete binary DFAs.
Input n m starts, followed by two transitions per state for each DFA. */
#include <stdio.h>
int main(void){int n,m,s,t,a[16][2],b[16][2],vis[16][16]={0},q[256][2],h=0,z=0;
if(scanf("%d%d%d%d",&n,&m,&s,&t)!=4||n<1||n>16||m<1||m>16||s<0||s>=n||t<0||t>=m)return 1;
for(int i=0;i<n;i++)for(int c=0;c<2;c++)if(scanf("%d",&a[i][c])!=1||a[i][c]<0||a[i][c]>=n)return 1;
for(int i=0;i<m;i++)for(int c=0;c<2;c++)if(scanf("%d",&b[i][c])!=1||b[i][c]<0||b[i][c]>=m)return 1;
q[z][0]=s;q[z++][1]=t;vis[s][t]=1;
while(h<z){int x=q[h][0],y=q[h++][1];for(int c=0;c<2;c++){int u=a[x][c],v=b[y][c];if(!vis[u][v]){vis[u][v]=1;q[z][0]=u;q[z++][1]=v;}}}
printf("reachable_product_states=%d\n",z);return 0;}