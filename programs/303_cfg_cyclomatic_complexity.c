/* Compute cyclomatic complexity M=E-N+2P for a directed CFG.
   Input n m, then m edges; P is number of weakly connected components.
   Multi-edges count separately. */
#include <stdio.h>
static int parent[100];
static int root(int x){return parent[x]==x?x:(parent[x]=root(parent[x]));}
int main(void){int n,m;if(scanf("%d%d",&n,&m)!=2||n<1||n>100||m<0||m>10000)return 1;
for(int i=0;i<n;i++)parent[i]=i;
for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;parent[root(u)]=root(v);}
int p=0;for(int i=0;i<n;i++)if(root(i)==i)p++;
printf("nodes=%d edges=%d components=%d complexity=%d\n",n,m,p,m-n+2*p);return 0;}
