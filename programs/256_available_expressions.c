/* Forward MUST dataflow for available expressions using bitmasks.
   Input: n m; CFG edges; then per-block GEN KILL (uint32 masks).
   Entry block 0 has empty IN; all blocks must be reachable. */
#include <stdio.h>
#include <stdint.h>
int main(void){
  int n,m,g[20][20]={0},vis[20]={0},q[20],h=0,t=0;
  uint32_t gen[20],kill[20],in[20],out[20];
  if(scanf("%d%d",&n,&m)!=2||n<1||n>20||m<0||m>400)return 1;
  for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||b<0||a>=n||b>=n)return 1;g[a][b]=1;}
  vis[0]=1;q[t++]=0;while(h<t){int u=q[h++];for(int v=0;v<n;v++)if(g[u][v]&&!vis[v])vis[v]=1,q[t++]=v;}
  if(t!=n){puts("UNREACHABLE");return 0;}
  for(int i=0;i<n;i++)if(scanf("%u%u",&gen[i],&kill[i])!=2)return 1;
  for(int i=0;i<n;i++)in[i]=i?UINT32_MAX:0,out[i]=gen[i]|(in[i]&~kill[i]);
  int changed=1;
  while(changed){changed=0;for(int u=0;u<n;u++){
    uint32_t x=u?UINT32_MAX:0;
    if(u)for(int p=0;p<n;p++)if(g[p][u])x&=out[p];
    uint32_t y=gen[u]|(x&~kill[u]);
    if(x!=in[u]||y!=out[u]){in[u]=x;out[u]=y;changed=1;}
  }}
  for(int i=0;i<n;i++)printf("%d IN=%u OUT=%u\n",i,in[i],out[i]);
  return 0;
}