/* Enumerate distinct nonempty RHS variants when nullable positions are optional.
Input: RHS uppercase string, nullable nonterminal set, e.g. ABC AC.
Maximum RHS length 12; '-' denotes epsilon. */
#include <stdio.h>
#include <string.h>
int main(void){char rhs[16],nullable[32],seen[4096][16];int count=0;
if(scanf("%15s%31s",rhs,nullable)!=2)return 1;int n=(int)strlen(rhs);
if(n>12)return 1;for(int i=0;i<n;i++)if(rhs[i]<'A'||rhs[i]>'Z')return 1;
int optional[12],k=0;for(int i=0;i<n;i++){optional[i]=-1;if(strchr(nullable,rhs[i]))optional[i]=k++;}
for(int mask=0;mask<(1<<k);mask++){char candidate[16];int p=0;
for(int i=0;i<n;i++)if(optional[i]<0||!(mask&(1<<optional[i])))candidate[p++]=rhs[i];
candidate[p]=0;int duplicate=0;for(int j=0;j<count;j++)if(!strcmp(seen[j],candidate))duplicate=1;
if(!duplicate){strcpy(seen[count++],candidate);puts(p?candidate:"-");}}
return 0;}