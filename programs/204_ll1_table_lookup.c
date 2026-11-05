/* Lookup predictive parsing table entry by nonterminal and terminal.
Input: n followed by n triples: nonterminal terminal production; then query pair. */
#include <stdio.h>
int main(void){int n;char nt[100],term[100],prod[100][64],x,y;if(scanf("%d",&n)!=1||n<0||n>100)return 1;for(int i=0;i<n;i++)if(scanf(" %c %c %63s",&nt[i],&term[i],prod[i])!=3)return 1;if(scanf(" %c %c",&x,&y)!=2)return 1;for(int i=0;i<n;i++)if(nt[i]==x&&term[i]==y){printf("production=%s\n",prod[i]);return 0;}puts("ERROR");return 0;}