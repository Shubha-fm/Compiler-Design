/* Check join stack heights in an acyclic bytecode control-flow graph.
   n instructions of PUSH, POP, ADD, NOP, HALT, then m graph edges.
   Entry is node 0; unreachable nodes ignored. */
#include <stdio.h>
#include <string.h>
int main(void){
  int n,m,g[40][40]={0},indeg[40]={0},height[40],q[40],head=0,tail=0,seen=0;
  char op[40][8];
  if(scanf("%d%d",&n,&m)!=2||n<1||n>40||m<0||m>1600)return 1;
  for(int i=0;i<n;i++){if(scanf("%7s",op[i])!=1)return 1;
    if(strcmp(op[i],"PUSH")&&strcmp(op[i],"POP")&&strcmp(op[i],"ADD")&&strcmp(op[i],"NOP")&&strcmp(op[i],"HALT"))return 1;
    height[i]=-1;
  }
  for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||v<0||u>=n||v>=n)return 1;
    if(!g[u][v]){g[u][v]=1;indeg[v]++;}
  }
  if(indeg[0]){puts("INVALID ENTRY");return 0;}
  for(int i=0;i<n;i++)if(!indeg[i])q[tail++]=i;
  height[0]=0;int invalid=0;
  while(head<tail){
    int u=q[head++];seen++;
    if(height[u]>=0){int h=height[u];
      if(!strcmp(op[u],"PUSH"))h++;
      if(!strcmp(op[u],"POP")){if(h<1)invalid=1;else h--;}
      if(!strcmp(op[u],"ADD")){if(h<2)invalid=1;else h--;}
      if(strcmp(op[u],"HALT")&&!invalid)for(int v=0;v<n;v++)if(g[u][v]){
        if(height[v]<0)height[v]=h;else if(height[v]!=h)invalid=1;
      }
    }
    for(int v=0;v<n;v++)if(g[u][v]&&!--indeg[v])q[tail++]=v;
  }
  if(seen!=n)puts("CYCLE");else puts(invalid?"UNSAFE":"SAFE");
  return 0;
}