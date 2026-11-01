/* Normalize CRLF and CR newline sequences to LF on stdin. */
#include <stdio.h>
int main(void){int c;while((c=getchar())!=EOF){if(c=='\r'){int d=getchar();putchar('\n');if(d!=EOF&&d!='\n')ungetc(d,stdin);}else putchar(c);}return 0;}