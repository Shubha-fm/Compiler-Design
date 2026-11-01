/* Summarize the total lengths of half-open live intervals. */
#include <stdio.h>
int main(void){int n;if(scanf("%d",&n)!=1||n<0||n>100)return 1;long sum=0;for(int i=0;i<n;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||b<a)return 1;sum+=b-a;}printf("total=%ld\n",sum);return 0;}