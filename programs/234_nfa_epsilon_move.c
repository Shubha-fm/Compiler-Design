/* One extended NFA move: epsilon-closure(move(epsilon-closure(S),a)).
States 0..n-1, epsilon edges marked '-', symbol edges a-z. */
#include <stdio.h>
#include <stdint.h>
static uint32_t closure(uint32_t set,const uint32_t ep[],int n){uint32_t prev;do{prev=set;for(int i=0;i<n;i++)if(set&(UINT32_C(1)<<i))set|=ep[i];}while(set!=prev);return set;}
int main(void){int n,m,k;uint32_t ep[32]={0},edges[32][26]={{0}},set=0,move=0;char c;
if(scanf("%d%d",&n,&m)!=2||n<1||n>32||m<0||m>1024)return 1;
for(int i=0;i<m;i++){int a,b;if(scanf("%d %c %d",&a,&c,&b)!=3||a<0||a>=n||b<0||b>=n)return 1;if(c=='-')ep[a]|=UINT32_C(1)<<b;else if(c>='a'&&c<='z')edges[a][c-'a']|=UINT32_C(1)<<b;else return 1;}
if(scanf("%d",&k)!=1||k<0||k>n)return 1;for(int i=0;i<k;i++){int v;if(scanf("%d",&v)!=1||v<0||v>=n)return 1;set|=UINT32_C(1)<<v;}if(scanf(" %c",&c)!=1||c<'a'||c>'z')return 1;
set=closure(set,ep,n);for(int i=0;i<n;i++)if(set&(UINT32_C(1)<<i))move|=edges[i][c-'a'];move=closure(move,ep,n);
printf("states:");for(int i=0;i<n;i++)if(move&(UINT32_C(1)<<i))printf(" %d",i);putchar('\n');return 0;}