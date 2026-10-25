/* Symmetric difference between even-ones and ends-in-zero DFAs. */
#include <stdio.h>
int main(void){char s[512];if(scanf("%511s",s)!=1)return 1;int odd=0,ends0=0;for(int i=0;s[i];i++){if(s[i]!='0'&&s[i]!='1'){puts("INVALID");return 0;}odd^=s[i]=='1';ends0=s[i]=='0';}puts((!odd)!=ends0?"ACCEPT":"REJECT");return 0;}