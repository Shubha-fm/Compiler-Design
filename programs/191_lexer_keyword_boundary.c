/* Distinguish exact keywords from identifiers (not substring matches). */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){char s[128];const char *k[]={"if","else","while","return","int","for"};if(scanf("%127s",s)!=1)return 1;if(!isalpha((unsigned char)s[0])&&s[0]!='_'){puts("INVALID");return 0;}for(int i=1;s[i];i++)if(!isalnum((unsigned char)s[i])&&s[i]!='_'){puts("INVALID");return 0;}for(int i=0;i<6;i++)if(!strcmp(s,k[i])){puts("KEYWORD");return 0;}puts("IDENTIFIER");return 0;}