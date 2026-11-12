/* Decode common LR parse ACTION cell strings: sN, rN, acc, error. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){char s[32];if(scanf("%31s",s)!=1)return 1;
if(!strcmp(s,"acc")){puts("ACCEPT");return 0;}
if(!strcmp(s,"error")){puts("ERROR");return 0;}
if((s[0]=='s'||s[0]=='r')&&s[1]){for(int i=1;s[i];i++)if(!isdigit((unsigned char)s[i])){puts("INVALID");return 0;}
printf("%s %s\n",s[0]=='s'?"SHIFT":"REDUCE",s+1);return 0;}
puts("INVALID");return 0;}