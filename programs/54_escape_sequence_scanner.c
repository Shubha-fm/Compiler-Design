/* Validate selected two-character C escape sequences. */
#include <stdio.h>
#include <string.h>
int main(void){char s[40];if(scanf("%39s",s)!=1)return 1;puts(strlen(s)==2&&s[0]=='\\'&&strchr("nrt0\\\"'",s[1])?"VALID":"INVALID");return 0;}