/* FIRST of one RHS, supplied nullable nonterminal flags and FIRST terminals.
   Example input: 2 A a 1 B b 0 AB => FIRST = a. */
#include <stdio.h>
#include <string.h>
int main(void){int n,nullable[26]={0},first[26]={0};char nt,t,seq[64];if(scanf("%d",&n)!=1||n<1||n>26)return 1;for(int i=0;i<n;i++){int b;if(scanf(" %c %c %d",&nt,&t,&b)!=3||nt<'A'||nt>'Z'||t<'a'||t>'z'||(b!=0&&b!=1))return 1;nullable[nt-'A']=b;first[nt-'A']=t;}if(scanf("%63s",seq)!=1)return 1;int all=1;printf("FIRST:");for(int i=0;seq[i];i++){if(seq[i]<'A'||seq[i]>'Z')return 1;int j=seq[i]-'A';if(first[j])printf(" %c",first[j]);if(!nullable[j]){all=0;break;}}if(all)printf(" epsilon");putchar('\n');return 0;}