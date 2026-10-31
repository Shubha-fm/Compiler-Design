/* Classify decimal, octal and hexadecimal unsigned integer tokens. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[128];if(scanf("%127s",s)!=1)return 1;int i=0,base=10;if(s[0]=='0'&&(s[1]=='x'||s[1]=='X')){base=16;i=2;if(!s[i]){puts("INVALID");return 0;}}else if(s[0]=='0'&&s[1])base=8;for(;s[i];i++){unsigned char c=s[i];if(base==16?!isxdigit(c):base==8?(c<'0'||c>'7'):!isdigit(c)){puts("INVALID");return 0;}}printf("BASE %d\n",base);return 0;}