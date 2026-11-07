/* Advance a subset of epsilon-free NFA states over one symbol.
Input: n, m, m transitions (from letter to), k starting states, symbol. */
#include <stdio.h>
#include <stdint.h>
int main(void){int n,m,k;uint32_t edge[26][32]={{0}},subset=0,result=0;char c;
if(scanf("%d%d",&n,&m)!=2||n<1||n>32||m<0||m>1000)return 1;
for(int i=0;i<m;i++){int u,v;if(scanf("%d %c %d",&u,&c,&v)!=3||u<0||u>=n||v<0||v>=n||c<'a'||c>'z')return 1;edge[c-'a'][u]|=UINT32_C(1)<<v;}
if(scanf("%d",&k)!=1||k<0||k>n)return 1;
for(int i=0;i<k;i++){int s;if(scanf("%d",&s)!=1||s<0||s>=n)return 1;subset|=UINT32_C(1)<<s;}
if(scanf(" %c",&c)!=1||c<'a'||c>'z')return 1;
for(int i=0;i<n;i++)if(subset&(UINT32_C(1)<<i))result|=edge[c-'a'][i];
printf("next:");for(int i=0;i<n;i++)if(result&(UINT32_C(1)<<i))printf(" %d",i);putchar('\n');return 0;}