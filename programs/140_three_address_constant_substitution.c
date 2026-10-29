/* Substitute one known constant into simplified TAC x = a + b. */
#include <stdio.h>
#include <string.h>
int main(void){char known[32],dst[32],a[32],b[32],eq[4],op[4];long value;if(scanf("%31s %ld %31s %3s %31s %3s %31s",known,&value,dst,eq,a,op,b)!=7)return 1;if(strcmp(eq,"=")||strcmp(op,"+"))return 1;printf("%s = ",dst);if(!strcmp(a,known))printf("%ld",value);else printf("%s",a);printf(" + ");if(!strcmp(b,known))printf("%ld",value);else printf("%s",b);putchar('\n');return 0;}