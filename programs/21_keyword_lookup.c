/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <string.h>
/* Detect reserved words. */
int main(void){char s[80];const char *k[]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};if(scanf("%79s",s)!=1)return 1;for(int i=0;i<32;i++)if(!strcmp(s,k[i])){puts("KEYWORD");return 0;}puts("NOT KEYWORD");return 0;}
