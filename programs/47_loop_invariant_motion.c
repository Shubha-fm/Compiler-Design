/* Identify constant-only loop invariant expression. Educational, limited-scope lab example. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){char x[40],eq[4],a[40],op[4],b[40];if(scanf("%39s %3s %39s %3s %39s",x,eq,a,op,b)!=5)return 1;if(strcmp(eq,"=")){puts("ERROR");return 0;}char *e1,*e2;strtol(a,&e1,10);strtol(b,&e2,10);puts(e1!=a&&!*e1&&e2!=b&&!*e2?"HOISTABLE":"UNKNOWN");return 0;}
