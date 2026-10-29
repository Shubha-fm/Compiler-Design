/* Determine peak stack depth needed to evaluate postfix token expression. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;int depth=0,peak=0;for(int i=0;s[i];i++){char c=s[i];if(isalpha((unsigned char)c)||isdigit((unsigned char)c)){depth++;if(depth>peak)peak=depth;}else if(c=='+'||c=='-'||c=='*'||c=='/'){if(depth<2){puts("INVALID");return 0;}depth--;}else{puts("INVALID");return 0;}}if(depth!=1)puts("INVALID");else printf("peak=%d\n",peak);return 0;}