/* Count operands and binary operators in postfix expression. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[256];int operands=0,ops=0;if(scanf("%255s",s)!=1)return 1;for(int i=0;s[i];i++){if(isalnum((unsigned char)s[i]))operands++;else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')ops++;else{puts("INVALID");return 0;}}printf("operands=%d operators=%d\n",operands,ops);return 0;}