/* Trace a DFA computing binary remainder modulo 5. */
#include <stdio.h>
int main(void){char bits[256];if(scanf("%255s",bits)!=1)return 1;int state=0;for(int i=0;bits[i];i++){if(bits[i]!='0'&&bits[i]!='1'){puts("INVALID");return 0;}state=(2*state+bits[i]-'0')%5;printf("%d\n",state);}return 0;}