/* Determine nullable nonterminals for an example grammar. Educational, limited-scope lab example. */
#include <stdio.h>

int main(void){int nullableA=1,nullableB=1,nullableS=nullableA&&nullableB;printf("A=%d B=%d S=%d\n",nullableA,nullableB,nullableS);return 0;}
