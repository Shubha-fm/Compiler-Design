/* Estimate simultaneous excess live intervals over a register budget.
   One timestep check per live-range endpoint, half-open intervals. */
#include <stdio.h>
int main(void){int n,r,a[100],b[100],peak=0;if(scanf("%d%d",&n,&r)!=2||n<0||n>100||r<1)return 1;for(int i=0;i<n;i++)if(scanf("%d%d",&a[i],&b[i])!=2||a[i]<0||b[i]<a[i]||b[i]>1000)return 1;for(int t=0;t<=1000;t++){int count=0;for(int i=0;i<n;i++)if(a[i]<=t&&t<b[i])count++;if(count>peak)peak=count;}printf("minimum_spills_at_peak=%d\n",peak>r?peak-r:0);return 0;}