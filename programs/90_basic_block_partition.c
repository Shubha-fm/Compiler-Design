/* Partition a linear instruction stream by supplied basic-block leaders.
   Input: N K followed by K zero-based leader indices. */
#include <stdio.h>
int main(void){int n,k,leader[101]={0};if(scanf("%d%d",&n,&k)!=2||n<1||n>100||k<0||k>100)return 1;leader[0]=1;for(int i=0;i<k;i++){int v;if(scanf("%d",&v)!=1||v<0||v>=n)return 1;leader[v]=1;}int start=0,index=0;for(int i=1;i<=n;i++)if(i==n||leader[i]){printf("B%d: [%d,%d]\n",index++,start,i-1);start=i;}return 0;}