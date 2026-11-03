/* Print postorder traversal of a binary AST rooted at index 0.
   n, then label left right per node, -1 = no child; rejects cycles. */
#include <stdio.h>
static int n,l[64],r[64],seen[64],bad;static char name[64];
static void walk(int x){if(x<0||bad)return;if(seen[x]==1){bad=1;return;}if(seen[x]==2)return;seen[x]=1;walk(l[x]);walk(r[x]);seen[x]=2;printf("%c ",name[x]);}
int main(void){if(scanf("%d",&n)!=1||n<1||n>64)return 1;for(int i=0;i<n;i++)if(scanf(" %c %d %d",&name[i],&l[i],&r[i])!=3||l[i]<-1||l[i]>=n||r[i]<-1||r[i]>=n)return 1;walk(0);if(bad){puts("CYCLE");return 1;}putchar('\n');return 0;}