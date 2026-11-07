/* Accept iff two complete binary DFAs both accept the same word. */
#include <stdio.h>
int main(void){int n,m,s,t,f[32],g[32],a[32][2],b[32][2];char w[512];
if(scanf("%d %d %d %d",&n,&m,&s,&t)!=4||n<1||m<1||n>32||m>32||s<0||s>=n||t<0||t>=m)return 1;
for(int i=0;i<n;i++)if(scanf("%d",&f[i])!=1||(f[i]!=0&&f[i]!=1))return 1;
for(int i=0;i<m;i++)if(scanf("%d",&g[i])!=1||(g[i]!=0&&g[i]!=1))return 1;
for(int i=0;i<n;i++)for(int c=0;c<2;c++)if(scanf("%d",&a[i][c])!=1||a[i][c]<0||a[i][c]>=n)return 1;
for(int i=0;i<m;i++)for(int c=0;c<2;c++)if(scanf("%d",&b[i][c])!=1||b[i][c]<0||b[i][c]>=m)return 1;
if(scanf("%511s",w)!=1)return 1;
for(int i=0;w[i];i++){if(w[i]!='0'&&w[i]!='1')return 1;int c=w[i]-'0';s=a[s][c];t=b[t][c];}
puts(f[s]&&g[t]?"ACCEPT":"REJECT");return 0;}