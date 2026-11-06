/* Track maximum depth of balanced parentheses in an expression. */
#include <stdio.h>
int main(void){int c,d=0,peak=0;while((c=getchar())!=EOF){if(c=='('){d++;if(d>peak)peak=d;}else if(c==')'){if(--d<0){puts("UNBALANCED");return 0;}}}if(d)puts("UNBALANCED");else printf("max_depth=%d\n",peak);return 0;}