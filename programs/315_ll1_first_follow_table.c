/* Demonstrate LL(1) table building for grammar S -> aA, A -> b | #.
   Prints production for token lookahead; '#' is epsilon and '$' is EOF.
   Input: nonterminal and lookahead. */
#include <stdio.h>
int main(void){char nt,look;if(scanf(" %c %c",&nt,&look)!=2)return 1;
if(nt=='S'&&look=='a')puts("S -> aA");
else if(nt=='A'&&look=='b')puts("A -> b");
else if(nt=='A'&&look=='$')puts("A -> #");
else puts("ERROR");return 0;}