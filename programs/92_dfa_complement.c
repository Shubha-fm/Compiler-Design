/* Complement of a DFA for binary strings ending in 1. */
#include <stdio.h>
int main(void){char s[512];if(scanf("%511s",s)!=1)return 1;int end=0;for(int i=0;s[i];i++){if(s[i]!='0'&&s[i]!='1'){puts("INVALID");return 0;}end=s[i]=='1';}puts(!end?"ACCEPT":"REJECT");return 0;}