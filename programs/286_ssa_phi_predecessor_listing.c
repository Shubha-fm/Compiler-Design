/* Emit one symbolic phi argument per distinct CFG predecessor for a block. */
#include <stdio.h>
int main(void){int n,m,block,g[40][40]={0};char var[32];
if(scanf("%d%d%d%31s",&n,&m,&block,var)!=4||n<1||n>40||m<0||m>1600||block<0||block>=n)return 1;
for(int i=0;i<m;i++){int u,v;if(scanf("%d%d",&u,&v)!=2||u<0||u>=n||v<0||v>=n)return 1;g[u][v]=1;}
printf("%s = phi(",var);int count=0;for(int u=0;u<n;u++)if(g[u][block]){if(count++)printf(", ");printf("%s@%d",var,u);}puts(")");return 0;}