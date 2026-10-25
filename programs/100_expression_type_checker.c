/* Type check one binary operation over int/float operands. */
#include <stdio.h>
#include <string.h>
int main(void){char a[16],b[16],op;if(scanf("%15s %c %15s",a,&op,b)!=3)return 1;int ai=!strcmp(a,"int"),af=!strcmp(a,"float"),bi=!strcmp(b,"int"),bf=!strcmp(b,"float");if(!(ai||af)||!(bi||bf)||!strchr("+-*/",op)){puts("TYPE ERROR");return 0;}puts(af||bf?"float":"int");return 0;}