/* Validate prefix binary expressions, one character per operand/operator. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;int need=1;for(int i=0;s[i];i++){if(need<=0){puts("INVALID");return 0;}if(isalnum((unsigned char)s[i]))need--;else if(strchr("+-*/",s[i]))need++;else{puts("INVALID");return 0;}}puts(need==0?"VALID":"INVALID");return 0;}