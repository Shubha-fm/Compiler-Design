/* Count equivalence classes of a complete binary DFA using table filling.
   Input: n, accepting flags, then two transitions per state. */
#include <stdio.h>
int main(void){
  int n,acc[32],delta[32][2],marked[32][32]={0};
  if(scanf("%d",&n)!=1||n<1||n>32)return 1;
  for(int i=0;i<n;i++)if(scanf("%d",&acc[i])!=1||(acc[i]!=0&&acc[i]!=1))return 1;
  for(int i=0;i<n;i++)for(int c=0;c<2;c++)
    if(scanf("%d",&delta[i][c])!=1||delta[i][c]<0||delta[i][c]>=n)return 1;
  for(int i=0;i<n;i++)for(int j=0;j<i;j++)if(acc[i]!=acc[j])marked[i][j]=1;
  int change=1;
  while(change){change=0;
    for(int i=0;i<n;i++)for(int j=0;j<i;j++)if(!marked[i][j]){
      for(int c=0;c<2;c++){int a=delta[i][c],b=delta[j][c];
        if(a<b){int tmp=a;a=b;b=tmp;}
        if(marked[a][b]){marked[i][j]=1;change=1;break;}
      }
    }
  }
  int classes[32],count=0;
  for(int i=0;i<n;i++){int found=-1;
    for(int j=0;j<i;j++)if(!marked[i][j]){found=classes[j];break;}
    classes[i]=found>=0?found:count++;
  }
  printf("classes=%d\n",count);
  for(int i=0;i<n;i++)printf("%d:%d\n",i,classes[i]);
  return 0;
}