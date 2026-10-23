/* Generate TAC for four operands and three left-associative '+' operations. */
#include <stdio.h>
int main(void){char a,b,c,d;if(scanf(" %c %c %c %c",&a,&b,&c,&d)!=4)return 1;printf("t1 = %c + %c\nt2 = t1 + %c\nt3 = t2 + %c\n",a,b,c,d);return 0;}