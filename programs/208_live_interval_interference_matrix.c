/* Build half-open live interval overlap matrix for n variables. */
#include <stdio.h>
int main(void){int n,l[20],r[20];if(scanf("%d",&n)!=1||n<1||n>20)return 1;for(int i=0;i<n;i++)if(scanf("%d%d",&l[i],&r[i])!=2||l[i]<0||r[i]<l[i])return 1;for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d%s",i!=j&&l[i]<r[j]&&l[j]<r[i],j+1==n?"":" ");putchar('\n');}return 0;}