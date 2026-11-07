/* Backward live-variable analysis of CFG blocks using 32-bit USE/DEF masks.
Input n m; edges; then USE DEF mask pairs for each block. */
#include <stdio.h>
#include <stdint.h>
int main(void){int n,m,g[32][32]={0};uint32_t use[32],def[32],in[32]={0},out[32]={0};
if(scanf("%d%d",&n,&m)!=2||n<1||n>32||m<0||m>1024)return 1;
for(int i=0;i<m;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||a>=n||b<0||b>=n)return 1;g[a][b]=1;}
for(int i=0;i<n;i++)if(scanf("%u%u",&use[i],&def[i])!=2)return 1;
int changed=1;while(changed){changed=0;for(int i=n-1;i>=0;i--){uint32_t o=0;for(int j=0;j<n;j++)if(g[i][j])o|=in[j];uint32_t v=use[i]|(o&~def[i]);if(v!=in[i]||o!=out[i]){in[i]=v;out[i]=o;changed=1;}}}
for(int i=0;i<n;i++)printf("%d IN=%u OUT=%u\n",i,in[i],out[i]);return 0;}