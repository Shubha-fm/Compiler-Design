/* Find leaders at jump targets and after jumps. Educational, limited-scope lab example. */
#include <stdio.h>

int main(void){int n,m,mark[101]={0},from,to;if(scanf("%d %d",&n,&m)!=2||n<1||n>100||m<0||m>100)return 1;mark[0]=1;for(int i=0;i<m;i++){if(scanf("%d %d",&from,&to)!=2||from<0||from>=n||to<0||to>=n)return 1;mark[to]=1;if(from+1<n)mark[from+1]=1;}printf("Leaders:");for(int i=0;i<n;i++)if(mark[i])printf(" %d",i);putchar('\n');return 0;}
