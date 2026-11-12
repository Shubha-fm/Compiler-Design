/* Convert a straight-line list of binary TAC instructions to indexed triples.
Input n, then lines destination = operand operation operand. */
#include <stdio.h>
#include <string.h>
int main(void){int n;char dest[64][32],a[32],b[32],op[4],eq[4];if(scanf("%d",&n)!=1||n<0||n>64)return 1;
for(int i=0;i<n;i++){if(scanf("%31s%3s%31s%3s%31s",dest[i],eq,a,op,b)!=5||strcmp(eq,"=")||strlen(op)!=1||!strchr("+-*/",op[0]))return 1;
for(int j=0;j<i;j++){if(!strcmp(a,dest[j])){static char buf[32];snprintf(buf,sizeof buf,"(%d)",j);strcpy(a,buf);}if(!strcmp(b,dest[j])){static char buf[32];snprintf(buf,sizeof buf,"(%d)",j);strcpy(b,buf);}}
printf("%d: (%s, %s, %s)\n",i,op,a,b);}
return 0;}