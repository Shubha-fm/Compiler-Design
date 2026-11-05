/* Check whether all symbols in a right-hand-side sequence are nullable.
Input: nullable nonterminals (uppercase, or '-') and RHS string. */
#include <stdio.h>
#include <string.h>
int main(void){char nullable[64],rhs[128];if(scanf("%63s %127s",nullable,rhs)!=2)return 1;for(int i=0;rhs[i];i++)if(rhs[i]<'A'||rhs[i]>'Z'||!strchr(nullable,rhs[i])){puts("NOT NULLABLE");return 0;}puts("NULLABLE");return 0;}