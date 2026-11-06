/* Determine whether assignment to one variable is dead from a live-out set.
   Assumes no observable side effects or traps in RHS. */
#include <stdio.h>
#include <string.h>
int main(void){char lhs[40],live[256];if(scanf("%39s %255s",lhs,live)!=2)return 1;for(int i=0;live[i];i++)if(live[i]==lhs[0]&&!lhs[1]){puts("LIVE");return 0;}puts("DEAD");return 0;}