/* Longest-match recognition for =, ==, !, !=, <, <=, >, >=. */
#include <stdio.h>
#include <string.h>
int main(void){char s[32];if(scanf("%31s",s)!=1)return 1;const char *ops[]={"==","!=","<=",">=","=","!","<",">"};for(int i=0;i<8;i++)if(!strcmp(s,ops[i])){printf("OPERATOR %s\n",ops[i]);return 0;}puts("INVALID");return 0;}