/* Forward may-analysis: OUT = GEN union (IN minus KILL).
   Input: n m, then edges, then per-node GEN and KILL unsigned bitmasks.
   Supports up to 20 blocks and 32 definition bits. */
#include <stdio.h>
#include <stdint.h>
int main(void){int n,m,g[20][20]={0};uint32_t gen[20],kill[20],in[20]={0},out[20]={0};if(scanf("%d%d",&n,&m)!=2||n<1||n>20||m<0||m>400)return 1;for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||b<0||a>=n||b>=n)return 1;g[a][b]=1;}for(int i=0;i<n;i++)if(scanf("%u%u",&gen[i],&kill[i])!=2)return 1;int change=1;while(change){change=0;for(int b=0;b<n;b++){uint32_t v=0;for(int a=0;a<n;a++)if(g[a][b])v|=out[a];uint32_t w=gen[b]|(v&~kill[b]);if(v!=in[b]||w!=out[b])in[b]=v,out[b]=w,change=1;}}for(int i=0;i<n;i++)printf("%d IN=%u OUT=%u\n",i,in[i],out[i]);return 0;}