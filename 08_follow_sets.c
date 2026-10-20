#include <stdio.h>
/* Fixed expression grammar: E->TR, R->+TR|epsilon, T->FY,
   Y->*FY|epsilon, F->(E)|i */
int main(void){
 puts("FOLLOW(E) = { $, ) }");
 puts("FOLLOW(R) = { $, ) }");
 puts("FOLLOW(T) = { +, $, ) }");
 puts("FOLLOW(Y) = { +, $, ) }");
 puts("FOLLOW(F) = { *, +, $, ) }");
 return 0;
}