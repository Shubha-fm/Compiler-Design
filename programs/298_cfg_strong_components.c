/* Kosaraju strongly connected components of a directed CFG.
   Input: n m then m edges; print component ID for each vertex. */
#include <stdio.h>
static int n,g[40][40],used[40],order[40],len,component[40];
static void forward(int u){used[u]=1;for(int v=0;v<n;v++)if(g[u][v]&&!used[v])forward(v);order[len++]=u;}
static void reverse(int u,int id){component[u]=id;for(int v=0;v<n;v++)if(g[v][u]&&component[v]<0)reverse(v,id);}
int main(void){int m;if(scanf("%d%d",&n,&m)!=2||n<1||n>40||m<0||m>1600)return 1;
for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;g[u][v]=1;}
for(int i=0;i<n;i++)if(!used[i])forward(i);
for(int i=0;i<n;i++){component[i]=-1;}\nint groups=0;
for(int i=n-1;i>=0;i--){int v=order[i];if(component[v]<0)reverse(v,groups++);}
printf("components=%d\n",groups);for(int i=0;i<n;i++)printf("vertex=%d component=%d\n",i,component[i]);return 0;}
