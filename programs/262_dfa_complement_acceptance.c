/* Complement a complete binary DFA by inverting its accepting-state test.
Input: n start, final flags, transition pairs, nonempty binary word. */
#include <stdio.h>
int main(void){int n,s,f[32],d[32][2];char w[512];if(scanf("%d%d",&n,&s)!=2||n<1||n>32||s<0||s>=n)return 1;
for(int i=0;i<n;i++)if(scanf("%d",&f[i])!=1||(f[i]!=0&&f[i]!=1))return 1;
for(int i=0;i<n;i++)for(int c=0;c<2;c++)if(scanf("%d",&d[i][c])!=1||d[i][c]<0||d[i][c]>=n)return 1;
if(scanf("%511s",w)!=1)return 1;for(int i=0;w[i];i++){if(w[i]!='0'&&w[i]!='1')return 1;s=d[s][w[i]-'0'];}
puts(f[s]?"REJECT":"ACCEPT");return 0;}