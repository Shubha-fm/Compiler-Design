#include <stdio.h>
/* Generates TAC for a*b+c*d, demonstrating temporaries. */
int main(void){
 puts("Expression: a*b+c*d");
 puts("t1 = a * b");
 puts("t2 = c * d");
 puts("t3 = t1 + t2");
 puts("result = t3");
 return 0;
}