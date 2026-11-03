/* Warn about nested block-comment openers, which standard C does not nest. */
#include <stdio.h>
int main(void){int c,prev=0,in=0,nested=0;while((c=getchar())!=EOF){if(!in){if(prev=='/'&&c=='*')in=1;}else{if(prev=='/'&&c=='*')nested++;if(prev=='*'&&c=='/')in=0;}prev=c;}printf("nested_openers=%d unterminated=%d\n",nested,in);return 0;}