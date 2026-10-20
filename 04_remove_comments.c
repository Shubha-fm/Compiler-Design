#include <stdio.h>
int main(void){
 int c,n,state=0;
 puts("Enter C code; Ctrl+D to finish:");
 while((c=getchar())!=EOF){
  if(state==0){if(c=='/'){n=getchar();if(n=='/')state=1;else if(n=='*')state=2;else{putchar(c);if(n!=EOF)ungetc(n,stdin);}}else putchar(c);}
  else if(state==1){if(c=='\n'){putchar(c);state=0;}}
  else if(state==2){if(c=='*')state=3;else if(c=='\n')putchar('\n');}
  else if(state==3){if(c=='/')state=0;else {if(c=='\n')putchar('\n');state=(c=='*')?3:2;}}
 }
 return 0;
}