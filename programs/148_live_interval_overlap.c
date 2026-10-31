/* Determine whether two half-open live ranges overlap. */
#include <stdio.h>
int main(void){int a,b,c,d;if(scanf("%d%d%d%d",&a,&b,&c,&d)!=4||a>b||c>d)return 1;puts(a<d&&c<b?"INTERFERE":"DISJOINT");return 0;}