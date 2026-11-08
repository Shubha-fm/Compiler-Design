/* Classify directed edges whose target dominates source (natural-loop back edges).
Input: CFG n,m, then directed edge pairs; entry is vertex 0. */
#include <stdio.h>
#include <stdint.h>
int main(void){int n,m,g[30][30]={0},seen[30]={0},q[30],h=0,t=0;uint32_t dom[30];
if(scanf("%d%d",&n,&m)!=2||n<1||n>30||m<0||m>900)return 1;
for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||a>=n||b<0||b>=n)return 1;g[a][b]=1;}
seen[0]=1;q[t++]=0;while(h<t){int u=q[h++];for(int v=0;v<n;v++)if(g[u][v]&&!seen[v])seen[v]=1,q[t++]=v;}
uint32_t all=(UINT32_C(1)<<n)-1u;for(int i=0;i<n;i++)dom[i]=i?all:1u;
int change=1;while(change){change=0;for(int v=1;v<n;v++)if(seen[v]){uint32_t d=all;for(int u=0;u<n;u++)if(seen[u]&&g[u][v])d&=dom[u];d|=UINT32_C(1)<<v;if(d!=dom[v]){dom[v]=d;change=1;}}}
int count=0;for(int u=0;u<n;u++)if(seen[u])for(int v=0;v<n;v++)if(g[u][v]&&(dom[u]&(UINT32_C(1)<<v))){printf("backedge %d %d\n",u,v);count++;}
printf("count=%d\n",count);return 0;}