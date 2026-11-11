/* Compute immediate postdominators using reverse-CFG dominator fixed point.
   Single designated exit; all vertices must be able to reach it. */
#include <stdio.h>
#include <stdint.h>
int main(void){
  int n,m,exit,g[30][30]={0},seen[30]={0},queue[30],h=0,t=0;
  uint32_t pd[30];
  if(scanf("%d%d%d",&n,&m,&exit)!=3||n<1||n>30||m<0||m>900||exit<0||exit>=n)return 1;
  for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||b<0||a>=n||b>=n)return 1;g[a][b]=1;}
  seen[exit]=1;queue[t++]=exit;
  while(h<t){int u=queue[h++];for(int v=0;v<n;v++)if(g[v][u]&&!seen[v])seen[v]=1,queue[t++]=v;}
  if(t!=n){puts("UNREACHABLE EXIT");return 0;}
  uint32_t all=(UINT32_C(1)<<n)-1;for(int i=0;i<n;i++)pd[i]=i==exit?(UINT32_C(1)<<i):all;
  int changed=1;
  while(changed){changed=0;for(int u=0;u<n;u++)if(u!=exit){
    uint32_t x=all;for(int v=0;v<n;v++)if(g[u][v])x&=pd[v];x|=UINT32_C(1)<<u;
    if(x!=pd[u]){pd[u]=x;changed=1;}
  }}
  for(int u=0;u<n;u++)if(u!=exit){int ip=-1;
    for(int candidate=0;candidate<n;candidate++)if(candidate!=u&&(pd[u]&(UINT32_C(1)<<candidate))){
      int nearest=1;
      for(int other=0;other<n;other++)if(other!=u&&other!=candidate&&(pd[u]&(UINT32_C(1)<<other))&&(pd[other]&(UINT32_C(1)<<candidate)))nearest=0;
      if(nearest){ip=candidate;break;}
    }
    printf("ipdom(%d)=%d\n",u,ip);
  }
  return 0;
}