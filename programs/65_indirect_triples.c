/* Show pointer table to three fixed triples. */
#include <stdio.h>
int main(void){const char *triple[]={"(+,a,b)","(*,(0),c)","(-,(1),d)"};int order[]={0,2,1};for(int i=0;i<3;i++)printf("%d -> %d %s\n",i,order[i],triple[order[i]]);return 0;}