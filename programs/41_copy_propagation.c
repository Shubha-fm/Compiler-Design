/* Propagate a single symbolic copy. Educational, limited-scope lab example. */
#include <stdio.h>
#include <string.h>
int main(void){char dst[40],eq[4],value[40];if(scanf("%39s %3s %39s",dst,eq,value)!=3)return 1;if(strcmp(eq,"=")){puts("ERROR");return 0;}printf("copy(%s) = %s\nuse(%s) => %s\n",dst,value,dst,value);return 0;}
