/* Extract use/def variables from t = x + y using single lowercase identifiers. */
#include <stdio.h>
int main(void){char d,a,b,eq,op;if(scanf(" %c %c %c %c %c",&d,&eq,&a,&op,&b)!=5)return 1;if(eq!='='||d<'a'||d>'z'||a<'a'||a>'z'||b<'a'||b>'z'){puts("INVALID");return 0;}printf("DEF: %c\nUSE: %c",d,a);if(a!=b)printf(" %c",b);putchar('\n');return 0;}