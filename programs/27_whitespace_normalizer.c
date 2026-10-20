/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <ctype.h>
/* Collapse runs of whitespace. */
int main(void){int c,space=0,started=0;while((c=getchar())!=EOF){if(isspace((unsigned char)c))space=started;else{if(space)putchar(' ');putchar(c);started=1;space=0;}}putchar('\n');return 0;}
