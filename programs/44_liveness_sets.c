/* Derive USE and DEF for a simple assignment. Educational, limited-scope lab example. */
#include <stdio.h>
#include <string.h>
int main(void){char x[40],eq[4],y[40],op[4],z[40];if(scanf("%39s %3s %39s %3s %39s",x,eq,y,op,z)!=5)return 1;if(strcmp(eq,"=")){puts("ERROR");return 0;}printf("DEF={%s} USE={%s",x,y);if(strcmp(y,z))printf(",%s",z);puts("}");return 0;}
