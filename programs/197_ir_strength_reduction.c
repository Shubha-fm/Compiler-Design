/* Replace x * 2^k with shift for nonnegative signed integers only.
   Input: dest operand factor. Emits original multiplication if factor is not a power of two. */
#include <stdio.h>
#include <string.h>
int main(void){char d[32],a[32];unsigned long long f;if(scanf("%31s%31s%llu",d,a,&f)!=3)return 1;if(f&&!(f&(f-1))){int k=0;while(f>1){f>>=1;k++;}printf("%s = %s << %d\n",d,a,k);}else printf("%s = %s * %llu\n",d,a,f);return 0;}