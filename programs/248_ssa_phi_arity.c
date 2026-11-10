/* Check phi argument count against a CFG block's predecessor count.
Input n,m, edges, block_id, phi_argument_count. Duplicate edges ignored. */
#include <stdio.h>
int main(void){int n,m,pred[40][40]={0},block,args;
if(scanf("%d%d",&n,&m)!=2||n<1||n>40||m<0||m>1600)return 1;
for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;pred[v][u]=1;}
if(scanf("%d%d",&block,&args)!=2||block<0||block>=n||args<0)return 1;
int count=0;for(int i=0;i<n;i++)count+=pred[block][i];
printf("predecessors=%d phi_args=%d %s\n",count,args,count==args?"VALID":"INVALID");return 0;}