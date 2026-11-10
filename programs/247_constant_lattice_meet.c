/* Meet of two compiler constant-propagation lattice values.
Values: UNDEF (no information), integer constant, NAC (not a constant).
UNDEF is the bottom value; differing constants meet to NAC. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{int kind;long value;} V;
static int parse(const char *s,V *v){char *end;
if(!strcmp(s,"UNDEF")){v->kind=0;return 1;}
if(!strcmp(s,"NAC")){v->kind=2;return 1;}
v->value=strtol(s,&end,10);v->kind=1;return end!=s&&!*end;}
int main(void){char a[64],b[64];V x,y;if(scanf("%63s%63s",a,b)!=2||!parse(a,&x)||!parse(b,&y))return 1;
V r;if(x.kind==0)r=y;else if(y.kind==0)r=x;else if(x.kind==2||y.kind==2)r=(V){2,0};else if(x.value==y.value)r=x;else r=(V){2,0};
if(r.kind==0)puts("UNDEF");else if(r.kind==2)puts("NAC");else printf("%ld\n",r.value);return 0;}