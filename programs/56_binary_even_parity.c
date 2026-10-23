/* DFA accepts strings containing an even number of 1 bits. */
#include <stdio.h>
int main(void){char s[512];if(scanf("%511s",s)!=1)return 1;int state=0;for(int i=0;s[i];i++){if(s[i]!='0'&&s[i]!='1'){puts("INVALID");return 0;}state^=s[i]=='1';}puts(state?"REJECT":"ACCEPT");return 0;}