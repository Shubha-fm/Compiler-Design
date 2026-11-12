/* Backward MUST very-busy expressions analysis with bitset transfer.
OUT[B] = intersection(IN[S]); IN[B] = GEN[B] union (OUT[B] minus KILL[B]).
Input n m edges, n GEN/KILL uint32 pairs; exit blocks have OUT=0. */
#include <stdio.h>
#include <stdint.h>
int main(void){int n,m,g[20][20]={0};uint32_t gen[20],kill[20],in[20],out[20];
if(scanf("%d%d",&n,&m)!=2||n<1||n>20||m<0||m>400)return 1;
for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||a>=n||b<0||b>=n)return 1;g[a][b]=1;}
for(int i=0;i<n;i++)if(scanf("%u%u",&gen[i],&kill[i])!=2)return 1;
for(int i=0;i<n;i++)in[i]=UINT32_MAX,out[i]=UINT32_MAX;
int changed=1;while(changed){changed=0;for(int u=n-1;u>=0;u--){uint32_t o=UINT32_MAX;int succ=0;
for(int v=0;v<n;v++)if(g[u][v]){o&=in[v];succ++;}
if(!succ)o=0;uint32_t x=gen[u]|(o&~kill[u]);
if(x!=in[u]||o!=out[u]){in[u]=x;out[u]=o;changed=1;}}}
for(int i=0;i<n;i++)printf("%d IN=%u OUT=%u\n",i,in[i],out[i]);return 0;}