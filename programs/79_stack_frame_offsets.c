/* Allocate consecutive 4-byte local slots in a sample stack frame. */
#include <stdio.h>
int main(void){int n;if(scanf("%d",&n)!=1||n<0||n>100)return 1;for(int i=0;i<n;i++)printf("local%d offset=-%d\n",i,(i+1)*4);return 0;}