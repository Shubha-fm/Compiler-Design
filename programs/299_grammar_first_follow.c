/* FIRST and FOLLOW fixed points for single-letter nonterminals and
   lowercase terminals. Rules: A rhs; # represents epsilon.
   Start symbol S. Output for all nonterminals occurring on LHS.
   FOLLOW uses '$' as EOF. */
#include <stdio.h>
#include <string.h>
static char lhs[100],rhs[100][64];static int rules;
static int first[26][27],follow[26][27],nullable[26],present[26];
static int put(int *cell){if(*cell)return 0;*cell=1;return 1;}
int main(void){if(scanf("%d",&rules)!=1||rules<1||rules>100)return 1;
for(int i=0;i<rules;i++){if(scanf(" %c %63s",&lhs[i],rhs[i])!=2||lhs[i]<'A'||lhs[i]>'Z')return 1;present[lhs[i]-'A']=1;
for(int j=0;rhs[i][j];j++){char c=rhs[i][j];if(!((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c=='#'&&j==0&&!rhs[i][1])))return 1;}}
int change=1;while(change){change=0;for(int i=0;i<rules;i++){int a=lhs[i]-'A',all=1;
if(rhs[i][0]=='#'&&!rhs[i][1]){change|=put(&nullable[a]);continue;}
for(int j=0;rhs[i][j];j++){char c=rhs[i][j];if(c>='a'&&c<='z'){change|=put(&first[a][c-'a']);all=0;break;}
int b=c-'A';for(int k=0;k<26;k++)if(first[b][k])change|=put(&first[a][k]);
if(!nullable[b]){all=0;break;}}
if(all)change|=put(&nullable[a]);}}
follow['S'-'A'][26]=1;change=1;
while(change){change=0;for(int i=0;i<rules;i++){int a=lhs[i]-'A';for(int j=0;rhs[i][j];j++){char c=rhs[i][j];if(c<'A'||c>'Z')continue;int b=c-'A',tailnullable=1;
for(int k=j+1;rhs[i][k];k++){char t=rhs[i][k];if(t>='a'&&t<='z'){change|=put(&follow[b][t-'a']);tailnullable=0;break;}
int d=t-'A';for(int x=0;x<26;x++)if(first[d][x])change|=put(&follow[b][x]);if(!nullable[d]){tailnullable=0;break;}}
if(tailnullable)for(int x=0;x<27;x++)if(follow[a][x])change|=put(&follow[b][x]);}}}
for(int i=0;i<26;i++)if(present[i]){printf("%c FIRST:",'A'+i);for(int x=0;x<26;x++)if(first[i][x])printf(" %c",'a'+x);if(nullable[i])printf(" #");putchar('\n');
printf("%c FOLLOW:",'A'+i);for(int x=0;x<26;x++)if(follow[i][x])printf(" %c",'a'+x);if(follow[i][26])printf(" $");putchar('\n');}
return 0;}
