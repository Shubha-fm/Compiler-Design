/* Propagate a constant through addition. Educational, limited-scope lab example. */
#include <stdio.h>

int main(void){long x,k;if(scanf("%ld %ld",&x,&k)!=2)return 1;printf("x = %ld\ny = %ld\n",x,x+k);return 0;}
