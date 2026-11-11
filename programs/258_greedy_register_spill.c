/* Greedy K-register coloring of undirected interference graph.
   Spill if none of K colors are available in vertex index order. */
#include <stdio.h>
int main(void){
  int n,m,k,g[40][40]={0},color[40],spills=0;
  if(scanf("%d%d%d",&n,&m,&k)!=3||n<1||n>40||m<0||m>1600||k<1||k>40)return 1;
  for(int i=0;i<n;i++)color[i]=-1;
  for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||v<0||u>=n||v>=n||u==v)return 1;g[u][v]=g[v][u]=1;}
  for(int i=0;i<n;i++){int used[40]={0};
    for(int j=0;j<i;j++)if(g[i][j]&&color[j]>=0)used[color[j]]=1;
    int chosen=-1;for(int c=0;c<k;c++)if(!used[c]){chosen=c;break;}
    color[i]=chosen;if(chosen<0){spills++;printf("v%d SPILL\n",i);}
    else printf("v%d R%d\n",i,chosen);
  }
  printf("spills=%d\n",spills);return 0;
}