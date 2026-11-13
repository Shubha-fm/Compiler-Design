/* Show a complete binary DFA state trace for input word.
Use 'eps' for the empty word. */
#include <stdio.h>
#include <string.h>
int main(void){int n,s,d[32][2];char w[256];if(scanf("%d%d",&n,&s)!=2||n<1||n>32||s<0||s>=n)return 1;
for(int i=0;i<n;i++)for(int c=0;c<2;c++)if(scanf("%d",&d[i][c])!=1||d[i][c]<0||d[i][c]>=n)return 1;
if(scanf("%255s",w)!=1)return 1;printf("trace: %d",s);
if(strcmp(w,"eps"))for(int i=0;w[i];i++){if(w[i]!='0'&&w[i]!='1')return 1;s=d[s][w[i]-'0'];printf(" %d",s);}
putchar('\n');return 0;}