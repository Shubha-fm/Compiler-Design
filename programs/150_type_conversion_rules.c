/* Determine widening conversion for two primitive arithmetic operand types. */
#include <stdio.h>
#include <string.h>
int main(void){char a[16],b[16];if(scanf("%15s %15s",a,b)!=2)return 1;const char *types[]={"char","int","float","double"};int x=-1,y=-1;for(int i=0;i<4;i++){if(!strcmp(a,types[i]))x=i;if(!strcmp(b,types[i]))y=i;}if(x<0||y<0){puts("INVALID");return 0;}int rank=x>y?x:y;if(rank==0)rank=1;printf("result=%s\n",types[rank]);return 0;}