/* Propagate a known copy x=y into one pure binary TAC expression.
Input: x y dst = left op right */
#include <stdio.h>
#include <string.h>
int main(void){char x[32],y[32],dst[32],eq[4],a[32],op[4],b[32];if(scanf("%31s%31s%31s%3s%31s%3s%31s",x,y,dst,eq,a,op,b)!=7)return 1;if(strcmp(eq,"=")||strlen(op)!=1||!strchr("+-*/",op[0]))return 1;printf("%s = %s %s %s\n",dst,!strcmp(a,x)?y:a,op,!strcmp(b,x)?y:b);return 0;}