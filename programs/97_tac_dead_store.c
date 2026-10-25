/* Eliminate first of two consecutive writes to the same variable.
   Only safe for constant RHS with no reads or side effects. */
#include <stdio.h>
int main(void){char a,b;long x,y;if(scanf(" %c %ld %c %ld",&a,&x,&b,&y)!=4)return 1;if(a==b)printf("%c = %ld\n",b,y);else printf("%c = %ld\n%c = %ld\n",a,x,b,y);return 0;}