/* PEG ordered-choice recognition: S <- 'a' ('b' / 'c') !. */
#include <stdio.h>
#include <string.h>
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;size_t n=strlen(s);puts(n==2&&s[0]=='a'&&(s[1]=='b'||s[1]=='c')?"ACCEPT":"REJECT");return 0;}
