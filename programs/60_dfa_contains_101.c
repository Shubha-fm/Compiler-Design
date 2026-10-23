/* DFA accepts binary strings containing substring 101. */
#include <stdio.h>
int main(void){char s[512];if(scanf("%511s",s)!=1)return 1;int st=0;for(int i=0;s[i];i++){char c=s[i];if(c!='0'&&c!='1'){puts("INVALID");return 0;}if(st==0)st=c=='1'?1:0;else if(st==1)st=c=='0'?2:1;else if(st==2)st=c=='1'?3:0;}puts(st==3?"ACCEPT":"REJECT");return 0;}