/* Recognize unsigned hexadecimal integer tokens of form 0x[0-9a-fA-F]+. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;
if(s[0]!='0'||(s[1]!='x'&&s[1]!='X')||!s[2]){puts("INVALID");return 0;}
for(int i=2;s[i];i++)if(!isxdigit((unsigned char)s[i])){puts("INVALID");return 0;}
puts("VALID");return 0;}