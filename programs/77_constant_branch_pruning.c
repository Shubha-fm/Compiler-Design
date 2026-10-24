/* Simplify if (constant) then A else B. */
#include <stdio.h>
int main(void){long condition;if(scanf("%ld",&condition)!=1)return 1;puts(condition?"REACHABLE: then":"REACHABLE: else");return 0;}