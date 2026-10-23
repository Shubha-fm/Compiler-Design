/* Mealy transducer outputs running parity of a bit stream. */
#include <stdio.h>
int main(void){char s[512];if(scanf("%511s",s)!=1)return 1;int parity=0;for(int i=0;s[i];i++){if(s[i]!='0'&&s[i]!='1'){puts("INVALID");return 0;}parity^=s[i]-'0';putchar('0'+parity);}putchar('\n');return 0;}