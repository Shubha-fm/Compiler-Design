/* Identify repeated pure TAC expressions of the form dst = left op right.
   Up to 100 lines, no writes to operands (simplified local CSE illustration). */
#include <stdio.h>
#include <string.h>
int main(void){int n;char d[100][32],a[100][32],b[100][32],op[100][8],eq[8];if(scanf("%d",&n)!=1||n<0||n>100)return 1;for(int i=0;i<n;i++){if(scanf("%31s %7s %31s %7s %31s",d[i],eq,a[i],op[i],b[i])!=5||strcmp(eq,"="))return 1;int found=-1;for(int j=0;j<i;j++)if(!strcmp(op[j],op[i])&&!strcmp(a[j],a[i])&&!strcmp(b[j],b[i])){found=j;break;}if(found>=0)printf("%s = %s /* reuse */\n",d[i],d[found]);else printf("%s = %s %s %s\n",d[i],a[i],op[i],b[i]);}return 0;}