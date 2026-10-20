/* Print AST shape for a+b*c. Educational, limited-scope lab example. */
#include <stdio.h>

int main(void){char a,op1,b,op2,c;if(scanf(" %c %c %c %c %c",&a,&op1,&b,&op2,&c)!=5)return 1;printf("ROOT(%c)\nLEFT(%c)\nRIGHT(%c,%c,%c)\n",op1,a,op2,b,c);return 0;}
