/* Forward stack-height analysis of a small acyclic bytecode CFG.
Instructions PUSH, POP, ADD, HALT; edges from each node are supplied.
Reject inconsistent merge heights and underflow; graph must be a DAG. */
#include <stdio.h>
#include <string.h>
int main(void){int n,m,g[40][40]={0},indeg[40]={0},q[40],h=0,t=0,height[40];char op[40][8];
if(scanf("%d%d",&n,&m)!=2||n<1||n>40||m<0||m>1600)return 1;
for(int i=0;i<n;i++){if(scanf("%7s",op[i])!=1||strcmp(op[i],"PUSH")&&strcmp(op[i],"POP")&&strcmp(op[i],"ADD")&&strcmp(op[i],"HALT"))return 1;height[i]=-1;}
for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;if(!g[u][v])g[u][v]=1,indeg[v]++;}
if(indeg[0]){puts("INVALID ENTRY");return 0;}for(int i=0;i<n;i++)if(!indeg[i])q[t++]=i;height[0]=0;int processed=0,bad=0;
while(h<t){int u=q[h++];processed++;if(height[u]>=0){int d=height[u];if(!strcmp(op[u],"PUSH"))d++;else if(!strcmp(op[u],"POP")){if(d<1)bad=1;else d--;}else if(!strcmp(op[u],"ADD")){if(d<2)bad=1;else d--;}if(!strcmp(op[u],"HALT")&&d>=0){}else for(int v=0;v<n;v++)if(g[u][v]){if(height[v]>=0&&height[v]!=d)bad=1;else if(height[v]<0)height[v]=d;}}
for(int v=0;v<n;v++)if(g[u][v]&&!--indeg[v])q[t++]=v;}
if(processed!=n)puts("CYCLE");else puts(bad?"UNSAFE":"SAFE");return 0;}