/* Normalize spaces and tabs inside one line. */
#include <stdio.h>
#include <ctype.h>
int main(void){int c,pending=0,seen=0;while((c=getchar())!=EOF&&c!='\n'){if(c==' '||c=='\t'){if(seen)pending=1;}else{if(pending)putchar(' ');putchar(c);seen=1;pending=0;}}putchar('\n');return 0;}