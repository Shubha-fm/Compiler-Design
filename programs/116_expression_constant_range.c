/* Interval addition for static analysis: input lowA highA lowB highB. */
#include <stdio.h>
int main(void){long a,b,c,d;if(scanf("%ld %ld %ld %ld",&a,&b,&c,&d)!=4||a>b||c>d)return 1;printf("[%ld,%ld]\n",a+c,b+d);return 0;}