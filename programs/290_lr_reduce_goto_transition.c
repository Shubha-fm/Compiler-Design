/* Demonstrate LR stack update after reducing a production.
Input: stack depth followed by states; pop count; GOTO state.
No table lookup or grammar validation is performed. */
#include <stdio.h>
int main(void){int n,states[100],pop,next;if(scanf("%d",&n)!=1||n<1||n>99)return 1;
for(int i=0;i<n;i++)if(scanf("%d",&states[i])!=1||states[i]<0)return 1;
if(scanf("%d%d",&pop,&next)!=2||pop<0||pop>=n||next<0)return 1;
n-=pop;states[n++]=next;printf("stack:");for(int i=0;i<n;i++)printf(" %d",states[i]);putchar('\n');return 0;}