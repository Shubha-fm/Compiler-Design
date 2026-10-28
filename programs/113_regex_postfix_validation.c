/* Validate postfix regular expression with operands a-z, binary | and ., unary *. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[256];int depth=0;if(scanf("%255s",s)!=1)return 1;for(int i=0;s[i];i++){char c=s[i];if(islower((unsigned char)c))depth++;else if(c=='*'){if(depth<1){puts("INVALID");return 0;}}else if(c=='|'||c=='.'){if(depth<2){puts("INVALID");return 0;}depth--;}else{puts("INVALID");return 0;}}puts(depth==1?"VALID":"INVALID");return 0;}