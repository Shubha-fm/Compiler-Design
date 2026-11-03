/* Validate escapes in a simplified regular expression: \\n, \\t, \\d, \\w, \\\\. */
#include <stdio.h>
#include <string.h>
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;for(int i=0;s[i];i++)if(s[i]=='\\'){i++;if(!s[i]||!strchr("ntdw\\",s[i])){puts("INVALID ESCAPE");return 0;}}puts("VALID");return 0;}