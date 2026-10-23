/* Moore machine reports initial and subsequent parity states. */
#include <stdio.h>
int main(void){char s[512];if(scanf("%511s",s)!=1)return 1;int state=0;putchar('0');for(int i=0;s[i];i++){if(s[i]!='0'&&s[i]!='1'){puts("\nINVALID");return 0;}state^=s[i]-'0';putchar('0'+state);}putchar('\n');return 0;}