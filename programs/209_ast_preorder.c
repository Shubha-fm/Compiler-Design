/* Preorder traversal of an indexed binary syntax tree rooted at node zero. */
#include <stdio.h>
static int n,l[64],r[64],state[64],bad;static char ch[64];
static void visit(int x){if(x<0||bad)return;if(state[x]){bad=1;return;}state[x]=1;printf("%c ",ch[x]);visit(l[x]);visit(r[x]);state[x]=2;}
int main(void){if(scanf("%d",&n)!=1||n<1||n>64)return 1;for(int i=0;i<n;i++)if(scanf(" %c%d%d",&ch[i],&l[i],&r[i])!=3||l[i]<-1||r[i]<-1||l[i]>=n||r[i]>=n)return 1;visit(0);putchar('\n');if(bad){puts("NOT A TREE");return 1;}return 0;}