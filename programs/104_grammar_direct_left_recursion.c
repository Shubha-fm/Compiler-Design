/* Detect immediate left recursion from one A->rhs grammar production. */
#include <stdio.h>
#include <string.h>
int main(void){char s[128];if(scanf("%127s",s)!=1)return 1;puts(strlen(s)>=4&&s[1]=='-'&&s[2]=='>'&&s[0]==s[3]?"LEFT RECURSIVE":"NOT LEFT RECURSIVE");return 0;}