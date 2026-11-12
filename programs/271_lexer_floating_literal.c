/* Recognize simplified decimal floats: digits.digits with optional exponent. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[256];int i=0,digits=0;
if(scanf("%255s",s)!=1)return 1;
while(isdigit((unsigned char)s[i])){i++;digits++;}
if(s[i]!='.'){puts("INVALID");return 0;}i++;
int after=0;while(isdigit((unsigned char)s[i])){i++;after++;}
if(!digits&&!after){puts("INVALID");return 0;}
if(s[i]=='e'||s[i]=='E'){i++;if(s[i]=='+'||s[i]=='-')i++;int exp=0;while(isdigit((unsigned char)s[i])){i++;exp++;}if(!exp){puts("INVALID");return 0;}}
puts(!s[i]?"VALID":"INVALID");return 0;}