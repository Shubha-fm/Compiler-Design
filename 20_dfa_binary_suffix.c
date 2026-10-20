#include <stdio.h>
/* DFA accepting binary strings ending with 01. */
int main(void) {
 char s[512]; int state=0;
 puts("Enter binary string:");
 if(scanf("%511s",s)!=1)return 1;
 for(int i=0;s[i];i++){
  if(s[i]!='0'&&s[i]!='1'){puts("Invalid alphabet");return 1;}
  if(state==0)state=s[i]=='0'?1:0;
  else if(state==1)state=s[i]=='0'?1:2;
  else state=s[i]=='0'?1:0;
 }
 puts(state==2?"Accepted":"Rejected");
 return 0;
}