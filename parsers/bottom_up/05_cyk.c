/* CYK dynamic programming for CNF grammar S->AB|BC, A->BA|a, B->CC|b, C->AB|a. */
#include <stdio.h>
#include <string.h>
int main(void){char s[64];if(scanf("%63s",s)!=1)return 1;int n=(int)strlen(s);unsigned char dp[64][64]={0};
for(int i=0;i<n;i++){if(s[i]=='a')dp[i][i]=1|4;else if(s[i]=='b')dp[i][i]=2;else{puts("REJECT");return 0;}}
for(int len=2;len<=n;len++)for(int i=0;i+len<=n;i++){int j=i+len-1;for(int k=i;k<j;k++){int l=dp[i][k],r=dp[k+1][j];if((l&2)&&(r&4))dp[i][j]|=1;if((l&2)&&(r&1))dp[i][j]|=4;if((l&4)&&(r&2))dp[i][j]|=1|4;if((l&4)&&(r&4))dp[i][j]|=2;}}
puts(dp[0][n-1]&1?"ACCEPT":"REJECT");return 0;}
