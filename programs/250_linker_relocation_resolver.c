/* Apply absolute relocations to a small table of 32-bit code words.
Input: code_word_count, words, symbol_count, name/address pairs,
relocation_count, word_index/symbol_name pairs. */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main(void){int n,s,r;uint32_t words[100],addr[100];char name[100][32];
if(scanf("%d",&n)!=1||n<1||n>100)return 1;
for(int i=0;i<n;i++)if(scanf("%u",&words[i])!=1)return 1;
if(scanf("%d",&s)!=1||s<0||s>100)return 1;
for(int i=0;i<s;i++)if(scanf("%31s%u",name[i],&addr[i])!=2)return 1;
if(scanf("%d",&r)!=1||r<0||r>100)return 1;
for(int i=0;i<r;i++){int index;char sym[32];if(scanf("%d%31s",&index,sym)!=2||index<0||index>=n)return 1;
int found=-1;for(int j=0;j<s;j++)if(!strcmp(sym,name[j])){found=j;break;}
if(found<0){printf("UNRESOLVED %s\n",sym);return 0;}words[index]=addr[found];}
printf("linked:");for(int i=0;i<n;i++)printf(" %u",words[i]);putchar('\n');return 0;}