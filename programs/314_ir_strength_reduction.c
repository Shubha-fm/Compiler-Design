/* Replace multiplication by power-of-two constants with left shifts.
   Input: count, then dest source multiplier (nonnegative). */
#include <stdio.h>
int main(void){int n;char dest[32],src[32];unsigned k;if(scanf("%d",&n)!=1||n<0||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%31s%31s%u",dest,src,&k)!=3)return 1;
if(k>0&&(k&(k-1u))==0u){int power=0;for(unsigned x=k;x>1u;x>>=1)power++;
printf("%s = %s << %d\n",dest,src,power);}
else printf("%s = %s * %u\n",dest,src,k);}
return 0;}