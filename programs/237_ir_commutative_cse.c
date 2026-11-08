/* Detect equivalent pure additions and multiplications under operand swapping.
Assumes operands do not change between instructions. */
#include <stdio.h>
#include <string.h>
int main(void){int n;char d[100][32],a[100][32],b[100][32],op[100][4],eq[4];
if(scanf("%d",&n)!=1||n<0||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%31s %3s %31s %3s %31s",d[i],eq,a[i],op[i],b[i])!=5||strcmp(eq,"=")||strlen(op[i])!=1||(op[i][0]!='+'&&op[i][0]!='*'))return 1;
int found=-1;for(int j=0;j<i;j++)if(!strcmp(op[i],op[j])&&((!strcmp(a[i],a[j])&&!strcmp(b[i],b[j]))||(!strcmp(a[i],b[j])&&!strcmp(b[i],a[j])))){found=j;break;}
if(found<0)printf("%s = %s %s %s\n",d[i],a[i],op[i],b[i]);else printf("%s = %s /* CSE */\n",d[i],d[found]);}return 0;}