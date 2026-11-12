/* Count filled cells in an LL(1) predictive table, detect conflicting entries.
Input: count, then nonterminal uppercase, terminal lowercase, production-ID. */
#include <stdio.h>
int main(void){int n,table[26][26]={0},count=0;if(scanf("%d",&n)!=1||n<0||n>500)return 1;
for(int i=0;i<n;i++){char a,b;int id;if(scanf(" %c %c %d",&a,&b,&id)!=3||a<'A'||a>'Z'||b<'a'||b>'z'||id<=0)return 1;
int *cell=&table[a-'A'][b-'a'];if(*cell&&*cell!=id){printf("CONFLICT %c %c\n",a,b);return 0;}if(!*cell){*cell=id;count++;}}
printf("filled_cells=%d\n",count);return 0;}