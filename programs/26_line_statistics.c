/* Compiler Design lab example. Build: gcc -std=c11 -Wall -Wextra FILE.c -o program
   Each example is deliberately limited to the grammar or transformation described. */
#include <stdio.h>
#include <ctype.h>
/* Count characters, words, and lines. */
int main(void){int c,chars=0,words=0,lines=0,in=0,last='\n';while((c=getchar())!=EOF){chars++;if(c=='\n')lines++;if(isspace((unsigned char)c))in=0;else if(!in){words++;in=1;}last=c;}if(chars&&last!='\n')lines++;printf("%d %d %d\n",chars,words,lines);return 0;}
