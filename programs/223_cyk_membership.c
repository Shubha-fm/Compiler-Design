/* CYK membership for CNF grammar with A..Z variables and a..z terminals.
Input: number of terminal rules, each A a; number of binary rules,
each A B C; nonempty word. Start variable S. Limit: 100 characters. */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main(void){int nt,nb;uint32_t terminal[26]={0},binary[26][26]={{0}},dp[100][100]={0};char A,B,C,w[101];
if(scanf("%d",&nt)!=1||nt<0||nt>1000)return 1;
for(int i=0;i<nt;i++){if(scanf(" %c %c",&A,&C)!=2||A<'A'||A>'Z'||C<'a'||C>'z')return 1;terminal[C-'a']|=UINT32_C(1)<<(A-'A');}
if(scanf("%d",&nb)!=1||nb<0||nb>1000)return 1;
for(int i=0;i<nb;i++){if(scanf(" %c %c %c",&A,&B,&C)!=3||A<'A'||A>'Z'||B<'A'||B>'Z'||C<'A'||C>'Z')return 1;binary[B-'A'][C-'A']|=UINT32_C(1)<<(A-'A');}
if(scanf("%100s",w)!=1)return 1;int n=(int)strlen(w);
for(int i=0;i<n;i++){if(w[i]<'a'||w[i]>'z')return 1;dp[i][i]=terminal[w[i]-'a'];}
for(int len=2;len<=n;len++)for(int i=0;i+len<=n;i++){int j=i+len-1;for(int k=i;k<j;k++)for(int b=0;b<26;b++)if(dp[i][k]&(UINT32_C(1)<<b))for(int c=0;c<26;c++)if(dp[k+1][j]&(UINT32_C(1)<<c))dp[i][j]|=binary[b][c];}
puts((dp[0][n-1]&(UINT32_C(1)<<('S'-'A')))?"ACCEPT":"REJECT");return 0;}