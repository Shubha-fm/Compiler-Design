/* Order grammar nonterminals by dependencies; report cycles.
Input n (A...); m relations A B meaning A depends on B. */
#include <stdio.h>
int main(void){int n,m,g[26][26]={0},deg[26]={0},q[26],h=0,t=0,order[26],k=0;
if(scanf("%d%d",&n,&m)!=2||n<1||n>26||m<0||m>676)return 1;
for(int i=0;i<m;i++){char a,b;if(scanf(" %c %c",&a,&b)!=2||a<'A'||a>='A'+n||b<'A'||b>='A'+n)return 1;int dep=a-'A',base=b-'A';if(!g[base][dep]){g[base][dep]=1;deg[dep]++;}}
for(int i=0;i<n;i++)if(!deg[i])q[t++]=i;
while(h<t){int u=q[h++];order[k++]=u;for(int v=0;v<n;v++)if(g[u][v]&&!--deg[v])q[t++]=v;}
if(k<n){puts("CYCLIC DEPENDENCY");return 0;}printf("order:");for(int i=0;i<n;i++)printf(" %c",'A'+order[i]);putchar('\n');return 0;}