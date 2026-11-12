/* Linear scan register assignment for sorted half-open intervals.
Input n k followed by n start/end pairs, sorted by nondecreasing start.
Current interval spills when all registers are occupied. */
#include <stdio.h>
int main(void){int n,k,s[50],e[50],until[16]={0};if(scanf("%d%d",&n,&k)!=2||n<0||n>50||k<1||k>16)return 1;
for(int i=0;i<n;i++)if(scanf("%d%d",&s[i],&e[i])!=2||s[i]<0||e[i]<=s[i]||(i&&s[i]<s[i-1]))return 1;
for(int i=0;i<n;i++){int slot=-1;for(int r=0;r<k;r++)if(until[r]<=s[i]){slot=r;break;}
if(slot<0)printf("v%d SPILL\n",i);else{until[slot]=e[i];printf("v%d R%d\n",i,slot);}}
return 0;}