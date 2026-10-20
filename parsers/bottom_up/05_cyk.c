/* CYK dynamic programming for CNF grammar S->AB|BC, A->BA|a, B->CC|b, C->AB|a. */
#include <stdio.h>
#include <string.h>
int main(void){char s[64];if(scanf("%63s",s)!=1)return 1;int n=(int)strlen(s);unsigned char dp[64][64]={0};
for(int i=0;i<n;i++){if(s[i]=='a')dp[i][i]=1|4;else if(s[i]=='b')dp[i][i]=2;else{puts("REJECT");return 0;}}
for(int len=2;len<=n;len++)for(int i=0;i+len<=n;i++){int j=i+len-1;for(int k=i;k<j;k++){int l=dp[i][k],r=dp[k+1][j];if(((l&1)&&(r&2))||((l&2)&&(r&4)))dp[i][j]|=8; /* S -> AB | BC */
if((l&2)&&(r&1))dp[i][j]|=1; /* A -> BA */
if((l&4)&&(r&4))dp[i][j]|=2; /* B -> CC */
if((l&1)&&(r&2))dp[i][j]|=4; /* C -> AB */
}}
puts(dp[0][n-1]&8?"ACCEPT":"REJECT");return 0;}
