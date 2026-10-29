/* Check a single CNF production A->BC, A->a, or optional S->#.
   Symbols use one uppercase nonterminal and one lowercase terminal. */
#include <stdio.h>
#include <string.h>
int main(void){char s[64];if(scanf("%63s",s)!=1)return 1;size_t n=strlen(s);int ok=n>=4&&s[0]>='A'&&s[0]<='Z'&&s[1]=='-'&&s[2]=='>';if(ok){if(n==4)ok=(s[3]>='a'&&s[3]<='z')||(s[0]=='S'&&s[3]=='#');else if(n==5)ok=s[3]>='A'&&s[3]<='Z'&&s[4]>='A'&&s[4]<='Z';else ok=0;}puts(ok?"CNF":"NOT CNF");return 0;}