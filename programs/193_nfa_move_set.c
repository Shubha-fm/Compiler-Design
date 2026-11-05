/* Compute MOVE(S, symbol) for an NFA of at most 30 states.
   Input: n m, then m transitions (from symbol to), then start-set count,
   start states, and query symbol. */
#include <stdio.h>
int main(void){int n,m,g[30][26][30]={0},source[30]={0},dest[30]={0},k;char c;if(scanf("%d%d",&n,&m)!=2||n<1||n>30||m<0||m>27000)return 1;for(int i=0;i<m;i++){int a,b;if(scanf("%d %c %d",&a,&c,&b)!=3||a<0||a>=n||b<0||b>=n||c<'a'||c>'z')return 1;g[a][c-'a'][b]=1;}if(scanf("%d",&k)!=1||k<0||k>n)return 1;for(int i=0;i<k;i++){int a;if(scanf("%d",&a)!=1||a<0||a>=n)return 1;source[a]=1;}if(scanf(" %c",&c)!=1||c<'a'||c>'z')return 1;for(int a=0;a<n;a++)if(source[a])for(int b=0;b<n;b++)if(g[a][c-'a'][b])dest[b]=1;printf("MOVE:");for(int i=0;i<n;i++)if(dest[i])printf(" %d",i);putchar('\n');return 0;}