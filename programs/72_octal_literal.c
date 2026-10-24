/* Validate C-style octal integer literal (0 followed by octal digits). */
#include <stdio.h>
int main(void){char s[128];if(scanf("%127s",s)!=1)return 1;if(s[0]!='0'){puts("INVALID");return 0;}for(int i=1;s[i];i++)if(s[i]<'0'||s[i]>'7'){puts("INVALID");return 0;}puts("VALID");return 0;}