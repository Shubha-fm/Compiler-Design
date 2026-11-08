/* Fixed-point nullable symbols of a CFG. Rules: A RHS; '-' is epsilon.
Only A-Z nonterminals and a-z terminals allowed. */
#include <stdio.h>
#include <ctype.h>
int main(void){int n,nullable[26]={0},changed=1;char lhs[128],rhs[128][64];
if(scanf("%d",&n)!=1||n<0||n>128)return 1;
for(int i=0;i<n;i++){if(scanf(" %c %63s",&lhs[i],rhs[i])!=2||lhs[i]<'A'||lhs[i]>'Z')return 1;}
while(changed){changed=0;for(int i=0;i<n;i++){int ok=1;if(rhs[i][0]=='-'&&rhs[i][1]==0)ok=1;else for(int j=0;rhs[i][j];j++){char c=rhs[i][j];if(c<'A'||c>'Z'||!nullable[c-'A']){ok=0;break;}}
if(ok&&!nullable[lhs[i]-'A'])nullable[lhs[i]-'A']=changed=1;}}
printf("nullable:");for(int i=0;i<26;i++)if(nullable[i])printf(" %c",'A'+i);putchar('\n');return 0;}