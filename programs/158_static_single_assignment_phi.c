/* Show phi insertion for two branches assigning the same variable. */
#include <stdio.h>
int main(void){char x[40];if(scanf("%39s",x)!=1)return 1;printf("%s_1 = then_value\n%s_2 = else_value\n%s_3 = phi(%s_1, %s_2)\n",x,x,x,x,x);return 0;}