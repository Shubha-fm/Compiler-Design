/* Print quadruples (operation, argument1, argument2, destination)
for simple three-address assignments. */
#include <stdio.h>
#include <string.h>
int main(void){int n;char dst[32],eq[4],a[32],op[4],b[32];
if(scanf("%d",&n)!=1||n<0||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%31s%3s%31s%3s%31s",dst,eq,a,op,b)!=5||strcmp(eq,"=")||strlen(op)!=1||!strchr("+-*/",op[0]))return 1;
printf("(%s, %s, %s, %s)\n",op,a,b,dst);}
return 0;}