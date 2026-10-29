/* Join two forward data-flow fact sets represented by unsigned bit vectors. */
#include <stdio.h>
int main(void){unsigned a,b;if(scanf("%u %u",&a,&b)!=2)return 1;printf("join=%u intersection=%u\n",a|b,a&b);return 0;}