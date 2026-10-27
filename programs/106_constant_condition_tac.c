/* Emit branch-free TAC for a known comparison of integer literals. */
#include <stdio.h>
int main(void){long a,b;char op;if(scanf("%ld %c %ld",&a,&op,&b)!=3)return 1;int v;if(op=='<')v=a<b;else if(op=='>')v=a>b;else if(op=='=')v=a==b;else{puts("UNSUPPORTED");return 0;}printf("condition = %d\n",v);return 0;}