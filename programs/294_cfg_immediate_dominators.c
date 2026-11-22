/* Iterative dominator sets and immediate-dominator reporting.
   Entry is node 0; all nodes must be reachable from entry. */
#include <stdio.h>
#include <stdint.h>
int main(void){int n,m,g[24][24]={{0}},vis[24]={0},q[24],h=0,t=0;uint32_t dom[24];
if(scanf("%d%d",&n,&m)!=2||n<1||n>24||m<0||m>576)return 1;
for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;g[u][v]=1;}
vis[0]=1;q[t++]=0;while(h<t){int u=q[h++];for(int v=0;v<n;v++)if(g[u][v]&&!vis[v])vis[v]=1,q[t++]=v;}
if(t!=n){puts("UNREACHABLE");return 0;}
uint32_t all=(UINT32_C(1)<<n)-1u;for(int i=0;i<n;i++)dom[i]=i?all:UINT32_C(1);
int change=1;while(change){change=0;for(int v=1;v<n;v++){uint32_t x=all;for(int u=0;u<n;u++)if(g[u][v])x&=dom[u];x|=UINT32_C(1)<<v;if(x!=dom[v])dom[v]=x,change=1;}}
for(int v=1;v<n;v++){int idom=-1;
for(int d=0;d<n;d++)if(d!=v&&(dom[v]&(UINT32_C(1)<<d))){int deepest=1;
for(int other=0;other<n;other++)if(other!=v&&other!=d&&(dom[v]&(UINT32_C(1)<<other))&&(dom[other]&(UINT32_C(1)<<d))){deepest=0;break;}
if(deepest){idom=d;break;}}
printf("idom(%d)=%d\n",v,idom);}
return 0;}
