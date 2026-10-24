/* DFA accepting binary strings without adjacent ones. */
#include <stdio.h>
int main(void){char s[512];if(scanf("%511s",s)!=1)return 1;int last=0;for(int i=0;s[i];i++){if(s[i]!='0'&&s[i]!='1'){puts("INVALID");return 0;}if(last&&s[i]=='1'){puts("REJECT");return 0;}last=s[i]=='1';}puts("ACCEPT");return 0;}