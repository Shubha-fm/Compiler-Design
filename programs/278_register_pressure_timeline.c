/* Print live interval pressure at each integer point in [0,horizon).
Half-open intervals [start,end) are used. */
#include <stdio.h>
int main(void){int n,h,a[100],b[100];if(scanf("%d%d",&n,&h)!=2||n<0||n>100||h<0||h>100)return 1;
for(int i=0;i<n;i++)if(scanf("%d%d",&a[i],&b[i])!=2||a[i]<0||b[i]<a[i]||b[i]>h)return 1;
for(int t=0;t<h;t++){int live=0;for(int i=0;i<n;i++)if(a[i]<=t&&t<b[i])live++;printf("%d:%d\n",t,live);}return 0;}