/* Expand a single-character bounded regex repetition c{m,n}, 0<=m<=n<=20.
Print all possible matching strings, using epsilon for an empty string. */
#include <stdio.h>
int main(void){char c;int m,n;if(scanf(" %c {%d,%d}",&c,&m,&n)!=3||c<'a'||c>'z'||m<0||n<m||n>20)return 1;
for(int k=m;k<=n;k++){if(!k)puts("epsilon");else{for(int i=0;i<k;i++)putchar(c);putchar('\n');}}return 0;}