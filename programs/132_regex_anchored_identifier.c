/* Full-string recognition of simplified identifier regex [A-Za-z_][A-Za-z0-9_]*. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;unsigned char c=s[0];if(!isalpha(c)&&c!='_'){puts("REJECT");return 0;}for(int i=1;s[i];i++){c=(unsigned char)s[i];if(!isalnum(c)&&c!='_'){puts("REJECT");return 0;}}puts("ACCEPT");return 0;}