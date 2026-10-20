/* Assign variable slots to registers and flag spills. Educational, limited-scope lab example. */
#include <stdio.h>

int main(void){int n,r;if(scanf("%d %d",&n,&r)!=2||n<1||n>100||r<1||r>32)return 1;for(int i=0;i<n;i++)printf("v%d -> R%d%s\n",i,i%r,i>=r?" (spill/reuse required)":"");return 0;}
