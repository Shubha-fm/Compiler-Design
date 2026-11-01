/* Symbol lookup across a nested scope chain. One variable per scope.
   Input: depth; then one name for each scope, outer to inner; query. */
#include <stdio.h>
#include <string.h>
int main(void){int n;char sym[32][40],key[40];if(scanf("%d",&n)!=1||n<1||n>32)return 1;for(int i=0;i<n;i++)if(scanf("%39s",sym[i])!=1)return 1;if(scanf("%39s",key)!=1)return 1;for(int i=n-1;i>=0;i--)if(!strcmp(key,sym[i])){printf("scope=%d\n",i);return 0;}puts("UNDECLARED");return 0;}