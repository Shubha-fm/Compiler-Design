/* Evaluate regex language a* b using derivatives of a small DFA.
   The implicit regex is a*b: zero or more 'a' followed by one 'b'. */
#include <stdio.h>
int main(void){char word[256];if(scanf("%255s",word)!=1)return 1;
int state=0;for(int i=0;word[i];i++){char c=word[i];if(c!='a'&&c!='b'){puts("INVALID");return 0;}
if(state==0)state=c=='a'?0:1;else state=2;}
puts(state==1?"MATCH":"NO MATCH");return 0;}
