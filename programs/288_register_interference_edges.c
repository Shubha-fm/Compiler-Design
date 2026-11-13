/* Emit interference edges for nonempty half-open live intervals.
Input: n then n start/end pairs. */
#include <stdio.h>
int main(void){int n,s[50],e[50],count=0;if(scanf("%d",&n)!=1||n<0||n>50)return 1;
for(int i=0;i<n;i++)if(scanf("%d%d",&s[i],&e[i])!=2||s[i]<0||e[i]<s[i])return 1;
for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(s[i]<e[j]&&s[j]<e[i]){printf("%d-%d\n",i,j);count++;}
printf("edges=%d\n",count);return 0;}