/* Count nodes in a parenthesized tree notation: each alphabetic character represents a node. */
#include <stdio.h>
#include <ctype.h>
int main(void){int c,count=0,depth=0,ok=1;while((c=getchar())!=EOF){if(isalpha((unsigned char)c))count++;else if(c=='(')depth++;else if(c==')'){if(--depth<0)ok=0;}else if(!isspace((unsigned char)c))ok=0;}if(depth||!ok)puts("INVALID");else printf("nodes=%d\n",count);return 0;}