/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>

/* Reduce multiplication by a positive power of two to shift. */
int main(void){char variable[40];unsigned n;if(scanf("%39s %u",variable,&n)!=2)return 1;if(n&&!(n&(n-1))){int shift=0;while(n>1){shift++;n>>=1;}printf("%s << %d\n",variable,shift);}else printf("%s * %u\n",variable,n);return 0;}
