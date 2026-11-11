/* Build a simplified LL(1) table from supplied SELECT sets.
   Each production: nonterminal uppercase, terminal set lowercase, RHS token.
   Detect conflicts when multiple productions occupy one table cell. */
#include <stdio.h>
#include <string.h>
int main(void){
  int n,table[26][26]={{0}};char lhs,rhs[64],select[128];
  if(scanf("%d",&n)!=1||n<0||n>100)return 1;
  for(int p=1;p<=n;p++){
    if(scanf(" %c %127s %63s",&lhs,select,rhs)!=3||lhs<'A'||lhs>'Z')return 1;
    for(int i=0;select[i];i++){char c=select[i];if(c<'a'||c>'z')return 1;
      if(table[lhs-'A'][c-'a'] && table[lhs-'A'][c-'a']!=p){
        printf("CONFLICT %c %c\n",lhs,c);return 0;
      }
      table[lhs-'A'][c-'a']=p;
    }
  }
  puts("LL1 TABLE OK");return 0;
}