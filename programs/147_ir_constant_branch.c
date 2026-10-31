/* Fold a constant conditional branch into a direct jump. */
#include <stdio.h>
int main(void){long x;char yes[32],no[32];if(scanf("%ld %31s %31s",&x,yes,no)!=3)return 1;printf("goto %s\n",x?yes:no);return 0;}