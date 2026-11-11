/* Remove C // and /* ... */ comments while preserving string and char literals.
   Newlines inside comments are preserved for source line positions. */
#include <stdio.h>
int main(void){
  enum { NORMAL, STRING, CHARACTER, LINE, BLOCK } state=NORMAL;
  int c, next, escaped=0, previous=0;
  while((c=getchar())!=EOF){
    if(state==NORMAL){
      if(c=='/' && (next=getchar())!=EOF){
        if(next=='/'){state=LINE;continue;}
        if(next=='*'){state=BLOCK;previous=0;continue;}
        putchar(c);ungetc(next,stdin);continue;
      }
      putchar(c);
      if(c=='"'){state=STRING;escaped=0;}
      else if(c==39){state=CHARACTER;escaped=0;}
    }else if(state==STRING || state==CHARACTER){
      putchar(c);
      if(escaped)escaped=0;
      else if(c=='\\')escaped=1;
      else if(c==(state==STRING?'"':39))state=NORMAL;
    }else if(state==LINE){
      if(c=='\n'){putchar('\n');state=NORMAL;}
    }else{
      if(c=='\n')putchar('\n');
      if(previous=='*'&&c=='/'){state=NORMAL;previous=0;}
      else previous=c;
    }
  }
  return 0;
}