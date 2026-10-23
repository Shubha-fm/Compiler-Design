/* Maximum nesting depth of balanced parentheses. */
#include <stdio.h>
int main(void){int c,depth=0,max=0,ok=1;while((c=getchar())!=EOF){if(c=='('){depth++;if(depth>max)max=depth;}else if(c==')'){if(--depth<0)ok=0;}}if(depth||!ok)puts("INVALID");else printf("%d\n",max);return 0;}