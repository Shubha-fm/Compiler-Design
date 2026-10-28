/* Produce correct three-address code for swapping two variables using a temporary. */
#include <stdio.h>
int main(void){char a[32],b[32];if(scanf("%31s %31s",a,b)!=2)return 1;printf("tmp = %s\n%s = %s\n%s = tmp\n",a,a,b,b);return 0;}