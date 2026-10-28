/* Check intersection of two FIRST terminal sets for an LL(1) FIRST/FIRST conflict. */
#include <stdio.h>
#include <string.h>
int main(void){char a[128],b[128];if(scanf("%127s %127s",a,b)!=2)return 1;for(int i=0;a[i];i++)if(strchr(b,a[i])){printf("CONFLICT %c\n",a[i]);return 0;}puts("DISJOINT");return 0;}