/* Resolve chains of unconditional jumps for labels 0..n-1.
Input n; target for each label, -1 if terminal. Detect cycles. */
#include <stdio.h>
int main(void){int n,t[100];if(scanf("%d",&n)!=1||n<1||n>100)return 1;for(int i=0;i<n;i++)if(scanf("%d",&t[i])!=1||t[i]<-1||t[i]>=n)return 1;for(int i=0;i<n;i++){int seen[100]={0},x=i;while(t[x]!=-1&&!seen[x]){seen[x]=1;x=t[x];}if(t[x]!=-1)printf("%d -> CYCLE\n",i);else printf("%d -> %d\n",i,x);}return 0;}