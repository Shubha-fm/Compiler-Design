/* Intersection: binary strings ending in 0 AND containing even number of ones. */
#include <stdio.h>
int main(void){char s[512];if(scanf("%511s",s)!=1)return 1;int parity=0,last=1;for(int i=0;s[i];i++){if(s[i]!='0'&&s[i]!='1'){puts("INVALID");return 0;}parity^=s[i]=='1';last=s[i]-'0';}puts(!parity&&!last?"ACCEPT":"REJECT");return 0;}