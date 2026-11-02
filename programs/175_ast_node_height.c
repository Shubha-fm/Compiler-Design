/* Height of a binary AST represented by child indices (-1 for missing).
   Input n followed by (left,right) for nodes 0..n-1, rooted at 0. */
#include <stdio.h>
static int n,left[100],right[100],state[100],height[100],ok=1;
static int visit(int x){if(x<0)return 0;if(state[x]==1){ok=0;return 0;}if(state[x]==2)return height[x];state[x]=1;int a=visit(left[x]),b=visit(right[x]);state[x]=2;return height[x]=1+(a>b?a:b);}
int main(void){if(scanf("%d",&n)!=1||n<1||n>100)return 1;for(int i=0;i<n;i++){if(scanf("%d%d",&left[i],&right[i])!=2||left[i]<-1||left[i]>=n||right[i]<-1||right[i]>=n)return 1;}int h=visit(0);if(!ok){puts("CYCLE");return 0;}printf("height=%d\n",h);return 0;}