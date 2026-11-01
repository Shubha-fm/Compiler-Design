/* Translate TAC x = a + b or x = a * b to three pseudo-register instructions. */
#include <stdio.h>
#include <string.h>
int main(void){char d[40],eq[4],a[40],op[4],b[40];if(scanf("%39s%3s%39s%3s%39s",d,eq,a,op,b)!=5)return 1;if(strcmp(eq,"=")||strlen(op)!=1||(op[0]!='+'&&op[0]!='*')){puts("UNSUPPORTED");return 0;}printf("MOV R0, %s\n%s R0, %s\nMOV %s, R0\n",a,op[0]=='+'?"ADD":"MUL",b,d);return 0;}