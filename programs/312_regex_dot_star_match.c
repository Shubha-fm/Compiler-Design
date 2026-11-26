/* Full-string pattern matching: '.' matches one char and '*' repeats previous.
   Input: pattern and text (single whitespace-free words); '#' means empty text. */
#include <stdio.h>
#include <string.h>
int main(void){char p[128],s[128];static unsigned char dp[128][128];
if(scanf("%127s%127s",p,s)!=2)return 1;if(!strcmp(s,"#"))s[0]=0;
int m=(int)strlen(p),n=(int)strlen(s);for(int i=0;i<m;i++)if(p[i]=='*'&&(i==0||p[i-1]=='*')){puts("INVALID");return 0;}
dp[0][0]=1;
for(int i=2;i<=m;i++)if(p[i-1]=='*')dp[i][0]=dp[i-2][0];
for(int i=1;i<=m;i++)for(int j=1;j<=n;j++){
if(p[i-1]=='*'&&i>=2){dp[i][j]=dp[i-2][j]||((p[i-2]=='.'||p[i-2]==s[j-1])&&dp[i][j-1]);}
else if(p[i-1]=='.'||p[i-1]==s[j-1])dp[i][j]=dp[i-1][j-1];}
puts(dp[m][n]?"MATCH":"NO MATCH");return 0;}